
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <arpa/inet.h>
#include <linux/ip.h>
#include <time.h>

#define PACKET_BUFFER_SIZE 65536

void print_packet( unsigned char *, int );
void print_ethernet_header( unsigned char * );
void print_ip_header( unsigned char * );

int main () { 

	// First, we need to create a socket 
	int my_socket = socket( AF_PACKET, SOCK_RAW, htons(ETH_P_ALL) );
	// arg0: Address Family - AF_INT is IP version 4 
	// arg1: Type - We need a raw socket 
	// arg2: Protocol - We only want to sniff IP packets 

	// If an error happened
	if ( my_socket < 0 ) {
		fprintf( stderr, "Error in creating the socket!\n" );
		shutdown( my_socket, 2 );
		// arg0: The socket we want to close 
		// arg1: how it should be closed. 2 is for Stopping both reception and transmission 
		return 1;
	}

	unsigned char *buffer = (unsigned char*) malloc( PACKET_BUFFER_SIZE );

	int counter = 0;

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

void print_packet( unsigned char *buffer, int data_size ) {
	printf( "\n\n\n" );
	print_ethernet_header( buffer );
	print_ip_header( buffer );
}

void print_ip_header( unsigned char *buffer ) {
	struct iphdr *ip_header = (struct iphdr *) ( buffer + sizeof( struct ethhdr ) );
	unsigned short ip_header_len = ip_header->ihl * 4;

	struct sockaddr_in source;
	source.sin_addr.s_addr = ip_header->saddr; 

	struct sockaddr_in destination; 
	destination.sin_addr.s_addr = ip_header->daddr; 

	printf( "IP Header: \n" );
	printf( "\t|-IP Version         : %d\n", (unsigned int) ip_header->version );
	printf( "\t|-IP Header Length   : %d Bytes\n", ip_header_len );
	printf( "\t|-Type of Service    : %d\n ", ip_header->tos );
	printf( "\t|-IP Total Length    : %d Bytes\n", ntohs( ip_header->tot_len ) );
	printf( "\t|-ID                 : %d\n", ntohs( ip_header->id ) );
	printf( "\t|-TTL                : %d\n", ip_header->ttl );
	printf( "\t|-Protocol           : %d\n", (unsigned int) ip_header->protocol );
	printf( "\t|-Checksum           : %d\n", ntohs( ip_header->check ) );
	printf( "\t|-Source IP          : %s\n", inet_ntoa( source.sin_addr ) );
	printf( "\t|-Destination IP     : %s\n", inet_ntoa( destination.sin_addr ) );

}

void print_ethernet_header( unsigned char *buffer ) {
	struct ethhdr *eth = ( struct ethhdr * ) buffer; 
	printf( "Ethernet Header: \n" );
	printf( "\t|-Destination Address: %.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n",
		eth->h_dest[0],
		eth->h_dest[1],
		eth->h_dest[2],
		eth->h_dest[3],
		eth->h_dest[4],
		eth->h_dest[5]
		);
	printf( "\t|-Source Address     : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n",
		eth->h_source[0],
		eth->h_source[1],
		eth->h_source[2],
		eth->h_source[3],
		eth->h_source[4],
		eth->h_source[5]
		);
	printf( "\t|-Protocol           : %u \n", (unsigned short) eth->h_proto );
}
