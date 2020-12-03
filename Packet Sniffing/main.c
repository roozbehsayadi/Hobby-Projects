
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <arpa/inet.h>
#include <time.h>

#define PACKET_BUFFER_SIZE 65536

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
		printf( "HERE!\n" );
		int data_size = recvfrom( my_socket, buffer, PACKET_BUFFER_SIZE, 0, &saddr, (socklen_t*)&saddr_size);
		if ( data_size < 0 ) {
			fprintf( stderr, "Error in recvfrom. Failed to get packets.\n" );
			shutdown( my_socket, 2 );
			return 1; 
		}
		printf("Got a packet! size: %d count: %d\n", saddr_size, counter++);
		fflush( stdout );
	}

	return 0;

}
