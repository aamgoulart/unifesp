#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>	
#include <arpa/inet.h>

#define ERROR_CONNECTION "Error on try connect on server\n"
#define SUCCESS_CONNETION "Conect on server\n"
#define ERROR_SOCKET "Error on create socker\n"
#define SUCESS_SOCKET "Socket create\n"
#define SUCESS_DISCONECT "Bye\n"
#define ERROR_DATA "Error on recieve data\n"
#define ERROR_CONVERT_HOSTNAME "Error on convert hostname to ip address"


int hostname_to_ip(char * hostname , char* ip);

int main(int argc, char **argv){

	int clientSocket, ret;
	struct sockaddr_in serverAddr;
	char buffer[1024], port, address;
	char ip[100];


    if(argc != 3) { 
        printf("Use: %s <porta> <endereço server>\n", argv[0]);
		return EXIT_FAILURE;

    }

	hostname_to_ip(argv[2] , ip);

    //SOCKET

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
        perror(ERROR_SOCKET);
		return EXIT_FAILURE;
	}
	printf(SUCESS_SOCKET);


    //CONNECT

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(atoi(argv[1]));
	serverAddr.sin_addr.s_addr = inet_addr(ip);

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
        perror(ERROR_CONNECTION);
		return EXIT_FAILURE;
	}
	printf(SUCCESS_CONNETION);
    
	while(1){
        // WRITE
		printf("Client says: \t");
		// gets(buffer);
		fgets(buffer, 1024, stdin);
		send(clientSocket, buffer, strlen(buffer), 0);

		if(strcmp(buffer, "exit") == 0){
			close(clientSocket);
			printf(SUCCESS_CONNETION);
			return EXIT_FAILURE;
		}

        // READ
		if(recv(clientSocket, buffer, 1024, 0) < 0){
			printf(ERROR_DATA);
		}else{
			printf("Server says: \t%s\n", buffer);
		}
	}

    close(clientSocket);

	return 0;
}

int hostname_to_ip(char * hostname , char* ip)
{
	struct hostent *he;
	struct in_addr **addr_list;
	int i;
		
	if ( (he = gethostbyname( hostname ) ) == NULL) 
	{
		perror(ERROR_CONVERT_HOSTNAME);
		return 1;
	}

	addr_list = (struct in_addr **) he->h_addr_list;
	
	for(i = 0; addr_list[i] != NULL; i++) 
	{
		//Return the first one;
		strcpy(ip , inet_ntoa(*addr_list[i]) );
		return 0;
	}
	
	return EXIT_FAILURE;
}