//UDP ECHO server

#include "UDP.h"

int main(void){
	//Declare and define variables
	int s;
	int len;
	char buffer[256];
	struct sockaddr_in servAddr;
	struct sockaddr_in clntAddr;
	int clntAddrLen;
	int server_port = 8001;
	//Build local(server) socket address
	memset(&servAddr,0,sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htonl(server_port);
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	//create socket
	if((PF_INET,SOCK_DGRAM,0)< 0)
	{
		perror("ERROR:socket failed!");
		exit(1);
	}
	//Bind socket to local address and port
	if ((bind(s,(struct sockaddr*)&servAddr,sizeof(servAddr))<0)){
		perror("ERROR: bind failed!");
		exit(1);
	}
	for(;;)  // Run forever
	{
		//Recieve String
		len = recvfrom(s, buffer,sizeof(buffer),0,(struct sockaddr*)&clntAddr,(socklen_t*)&clntAddrLen);
		//send String
		sendto(s,buffer,len,0,(struct sockAddr*)&clntAddr,sizeof(clntAddr));

	}//End of for loop
}//End of echo server program
