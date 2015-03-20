/*
 * Client.cpp
 *
 *  Created on: 20/03/2015
 *      Author: Kenneth
 */

#include "Client.h"
int main (int argc, char*argv[])
{
	int s;						//socket descriptor
	int len;					//Length of string to be echoed
	char* servName;				//Server name
	int servPort;				//server port
	char* string;				//String to be echoed
	char buffer[256+1];			//Data buffer
	struct sockaddr_inAddr;		//Server socket address

	// Check and set program arguments
	if(argc !=3)
	{
		printf("Error: three arguments are needed!");
		exit(1);
	}
	servName = argv[1];
	servPort = atoi(argv[2]);
	string = argv[3];
	//build the server socket adress

	memset (&servAddr, 0, sizeof (servAddr));
	servAddr.sin_family = AF_INET;
	inet_pton (AF_INET, servName, &servAddr.sin_addr);
	servAdd.sin_port=htons(servPort);

	//create socket
	if ((s = socket (PF_INET, SOCK_DGRAM, 0) < 0)) {
	perror ("Error: Socket failed!");
	exit (1);
	}
	//send echo string
	len = sendto (s, string, strlen (string), 0, (struct sockaddr)&servAddr, sizeof (servAddr));

	//Reccive echo string
	recvfrom(s,buffer,len,0,NULL,NULL);

	//Print and verify echoed string
	buffer[len]='\0';
	printf("Echo string received: ");
	fputs (buffer, stdout);

	//Close the socket
	close(s);s

	//Stop the program
	exit(0);
}
//End of  echo client program
