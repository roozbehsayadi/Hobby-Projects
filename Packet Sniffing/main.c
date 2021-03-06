
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <netinet/ip_icmp.h>
#include <netinet/igmp.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <time.h>

#define PACKET_BUFFER_SIZE 65536

void print_packet( unsigned char *, int );
void print_ethernet_header( unsigned char * );
void print_ip_header( unsigned char * );
void print_tcp_packet( unsigned char *, int );
void print_udp_packet( unsigned char *, int );
void print_icmp_packet( unsigned char *, int );
void print_igmp_packet( unsigned char *, int );
void print_ip_protocol_name( int );

int main () { 

	// First, we need to create a socket 
	int my_socket = socket( AF_PACKET, SOCK_RAW, htons(ETH_P_ALL) );
	// arg0: Address Family - AF_PACKET is used to play with packets 
	// arg1: Type - We need a raw socket 
	// arg2: Protocol - We sniff every packet, along with their ethernet headers

	// If an error happened
	if ( my_socket < 0 ) {
		fprintf( stderr, "Error in creating the socket!\n" );
		shutdown( my_socket, 2 );
		// arg0: The socket we want to close 
		// arg1: how it should be closed. 2 is for Stopping both reception and transmission 
		return 1;
	}

	// The buffer used to store packet information each time we recieve one 
	unsigned char *buffer = (unsigned char*) malloc( PACKET_BUFFER_SIZE );

	while ( 1 ) {
		struct sockaddr saddr;
		int saddr_size = sizeof saddr; 
		int data_size = recvfrom( my_socket, buffer, PACKET_BUFFER_SIZE, 0, &saddr, (socklen_t*)&saddr_size);
		if ( data_size < 0 ) {
			fprintf( stderr, "Error in recvfrom. Failed to get packets.\n" );
			shutdown( my_socket, 2 );
			return 1; 
		}
		print_packet( buffer, data_size );
	}

	shutdown( my_socket, 2 );
	printf( "Finished!" );

	return 0;

}

// Find out the type of backet stored in buffer
// and print its data accordingly 
void print_packet( unsigned char *buffer, int data_size ) {
	printf( "\n\n\n" );

	struct iphdr *ip_header = (struct iphdr *) ( buffer + sizeof( struct ethhdr ) );
	int ip_protocol = ip_header->protocol;
	if ( ip_protocol == IPPROTO_ICMP ) 
		print_icmp_packet( buffer, data_size );
	else if ( ip_protocol == IPPROTO_TCP )
		print_tcp_packet( buffer, data_size );
	else if ( ip_protocol == IPPROTO_UDP )
		print_udp_packet( buffer, data_size );
	else if ( ip_protocol == IPPROTO_IGMP ) 
		print_igmp_packet( buffer, data_size );
	else
		print_ip_protocol_name( ip_protocol );

}

void print_udp_packet( unsigned char *buffer, int data_size ) {

	printf( "***********************UDP Packet***********************\n\n");

	print_ethernet_header( buffer );
	printf( "\n" );
	print_ip_header( buffer );
	printf( "\n" );

	struct iphdr *ip_header = (struct iphdr *) ( buffer + sizeof( struct ethhdr ) );
	int ip_header_len = ip_header->ihl * 4;

	struct udphdr *udp_header = (struct udphdr *) ( buffer + ip_header_len + sizeof( struct ethhdr ) );

	printf( "UDP Header:\n" );
	printf( "\t|-Source Port        : %d\n", ntohs( udp_header->source ) );
	printf( "\t|-Destination Port   : %d\n", ntohs( udp_header->dest ) );
	printf( "\t|-UDP Length         : %d\n", ntohs( udp_header->len ) );
	printf( "\t|-UDP Checksum       : %d\n", ntohs( udp_header->check ) );
	
	printf( "\n\n" );

}

void print_tcp_packet( unsigned char *buffer, int data_size ) {

	printf( "***********************TCP Packet***********************\n\n");

	print_ethernet_header( buffer );
	printf( "\n" );
	print_ip_header( buffer );
	printf( "\n" );

	struct iphdr *ip_header = (struct iphdr *) ( buffer + sizeof( struct ethhdr ) );
	int ip_header_len = ip_header->ihl * 4;

	struct tcphdr *tcp_header = (struct tcphdr *) ( buffer + sizeof( struct ethhdr ) + ip_header_len );

	printf( "TCP Header:\n" );
	printf( "\t|-Source Port          : %u\n", ntohs( tcp_header->source ) );
	printf( "\t|-Destination Port     : %u\n", ntohs( tcp_header->dest ) );
	printf( "\t|-Sequence Number      : %u\n", ntohl( tcp_header->seq ) );
	printf( "\t|-Acknowledge Number   : %u\n", ntohl( tcp_header->ack ) );
	printf( "\t|-Header Length        : %d Bytes\n", (unsigned int) tcp_header->doff*4 );
	printf( "\t|-Urgent Flag          : %d\n", (unsigned int) tcp_header->urg );
	printf( "\t|-Acknowledgement Flag : %d\n", (unsigned int) tcp_header->ack );
	printf( "\t|-Push Flag            : %d\n", (unsigned int) tcp_header->psh );
	printf( "\t|-Reset Flag           : %d\n", (unsigned int) tcp_header->rst );
	printf( "\t|-Synchronise Flag     : %d\n", (unsigned int) tcp_header->syn );
	printf( "\t|-Finish Flag          : %d\n", (unsigned int) tcp_header->fin );
	printf( "\t|-Window Flag          : %d\n", ntohs( tcp_header->window ) );
	printf( "\t|-Checksum Flag        : %d\n", ntohs( tcp_header->check ) );
	printf( "\t|-Urgent Flag          : %d\n", tcp_header->urg_ptr );

	printf( "\n\n" );

}

void print_icmp_packet( unsigned char *buffer, int data_size ) {

	printf( "***********************ICMP Packet***********************\n\n");

	print_ethernet_header( buffer );
	printf( "\n" );
	print_ip_header( buffer );
	printf( "\n" );

	struct iphdr *ip_header = (struct iphdr *) ( buffer + sizeof( struct ethhdr ) );
	int ip_header_len = ip_header->ihl * 4;

	struct icmphdr *icmp_header = (struct icmphdr *) ( buffer + sizeof( struct ethhdr ) + ip_header_len );

	printf( "ICMP Header:\n" );
	printf( "\t|-Type    : %d ", (unsigned int) icmp_header->type );
	if ( (unsigned int) icmp_header->type == ICMP_TIME_EXCEEDED ) 
		printf( "\t(TTL Expired)\n" );
	else if ( (unsigned int) icmp_header->type == ICMP_ECHOREPLY )
		printf( "\t(Echo Reply)\n" );
	printf( "\t|-Code    : %d\n", icmp_header->code );
	printf( "\t|-Checksum: %d\n", ntohs( icmp_header->checksum ) );

	printf( "\n\n" );

}

void print_igmp_packet( unsigned char * buffer, int data_size ) {

	printf( "***********************IGMP Packet***********************\n\n");

	print_ethernet_header( buffer );
	printf( "\n" );
	print_ip_header( buffer );
	printf( "\n" );

	struct iphdr *ip_header = (struct iphdr *) ( buffer + sizeof( struct ethhdr ) );
	int ip_header_len = ip_header->ihl * 4;

	struct igmp *igmp_header = (struct igmp *) ( buffer + sizeof( struct ethhdr ) + ip_header_len );

	printf( "IGMP HEADER:\n" );
	printf( "\t|-Type      : %d\n", (unsigned int) igmp_header->igmp_type );
	printf( "\t|-Code      : %d\n", (unsigned int) igmp_header->igmp_code );
	printf( "\t|-Checksum  : %d\n", ntohs( igmp_header->igmp_cksum ) );
	printf( "\t|-Group     : %s\n", inet_ntoa( igmp_header->igmp_group ) );

}

void print_ip_header( unsigned char *buffer ) {
	struct iphdr *ip_header = (struct iphdr *) ( buffer + sizeof( struct ethhdr ) );
	unsigned short ip_header_len = ip_header->ihl * 4;

	struct sockaddr_in source;
	source.sin_addr.s_addr = ip_header->saddr; 

	struct sockaddr_in destination; 
	destination.sin_addr.s_addr = ip_header->daddr; 

	printf( "IP Header: \n" );
	printf( "\t|-IP Version           : %d\n", (unsigned int) ip_header->version );
	printf( "\t|-IP Header Length     : %d Bytes\n", ip_header_len );
	printf( "\t|-Type of Service      : %d\n ", ip_header->tos );
	printf( "\t|-IP Total Length      : %d Bytes\n", ntohs( ip_header->tot_len ) );
	printf( "\t|-ID                   : %d\n", ntohs( ip_header->id ) );
	printf( "\t|-TTL                  : %d Seconds\n", ip_header->ttl );
	printf( "\t|-Protocol             : %d\n", (unsigned int) ip_header->protocol );
	printf( "\t|-Checksum             : %d\n", ntohs( ip_header->check ) );
	printf( "\t|-Source IP            : %s\n", inet_ntoa( source.sin_addr ) );
	printf( "\t|-Destination IP       : %s\n", inet_ntoa( destination.sin_addr ) );

}

void print_ethernet_header( unsigned char *buffer ) {
	struct ethhdr *eth = ( struct ethhdr * ) buffer; 
	printf( "Ethernet Header: \n" );
	printf( "\t|-Destination Address  : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n",
		eth->h_dest[0],
		eth->h_dest[1],
		eth->h_dest[2],
		eth->h_dest[3],
		eth->h_dest[4],
		eth->h_dest[5]
		);
	printf( "\t|-Source Address       : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n",
		eth->h_source[0],
		eth->h_source[1],
		eth->h_source[2],
		eth->h_source[3],
		eth->h_source[4],
		eth->h_source[5]
		);
	printf( "\t|-Protocol             : %u \n", (unsigned short) eth->h_proto );
}


void print_ip_protocol_name( int protocol ) {
	switch ( protocol ) {
		case IPPROTO_IP:
			printf( "Dummy protocol for TCP\n" );
			break; 
		case IPPROTO_ICMP:
			printf( "Internet Control Message Protocol\n" );
			break;
		case IPPROTO_IGMP:
			printf( "Internet Group Management Protocol\n" );
			break;
		case IPPROTO_IPIP:
			printf( "IPIP tunnels (older KA9Q tunnels use 94)\n");
			break;
		case IPPROTO_TCP:
			printf( "Transmissio Control Protocol\n" );
			break;
		case IPPROTO_EGP:
			printf( "Exterior Gateway Protocol\n" );
			break;
		case IPPROTO_PUP:
			printf( "Xerox PUP\n" );
			break;
		case IPPROTO_UDP:
			printf( "User Datagram Protocol\n" );
			break;
		case IPPROTO_IDP:
			printf( "XNS IDP Protocol\n" );
			break;
		case IPPROTO_TP:
			printf( "SO Transport Protocol Class 4\n" );
			break;
		case IPPROTO_DCCP:
			printf( "Datagram Congestion Control Protocol\n" );
			break;
		case IPPROTO_IPV6:
			printf( "IPv6 Encapsulation\n" );
			break;
		case IPPROTO_RSVP:
			printf( "Reservation Protocol\n" );
			break; 
		case IPPROTO_GRE:
			printf( "General Routing Encapsulation\n" );
			break;
		case IPPROTO_ESP:
			printf( "Encapsulatin Security Payload\n" );
			break;
		case IPPROTO_AH:
			printf( "Authentication Header\n" );
			break; 
		case IPPROTO_MTP:
			printf( "Multicast Transport Protocol\n" );
			break;
		case IPPROTO_BEETPH:
			printf( "IP Option Pseudo Header for BEET\n" );
			break;
		case IPPROTO_ENCAP:
			printf( "Encapsulation Header\n" );
			break;
		case IPPROTO_PIM:
			printf( "Protocol Independent Multicast\n" );
			break;
		case IPPROTO_COMP:
			printf( "Compresion Header Protocol\n" );
			break;
		case IPPROTO_SCTP:
			printf( "Stream Control Transmission Protocol\n" );
			break;
		case IPPROTO_UDPLITE:
			printf( "UDP-Lite Protocol\n" );
			break;
		case IPPROTO_MPLS:
			printf( "MPLS in IP\n" );
			break;
		case IPPROTO_RAW:
			printf( "Raw IP Packets\n" );
			break;
		case 128:
			printf( "Service-Specific Connection-Oriented Protocol in a Multilink and Connectionless Environment\n" );
			break;
		default:
			printf( "%d\n", (unsigned int) protocol );
	}
}

