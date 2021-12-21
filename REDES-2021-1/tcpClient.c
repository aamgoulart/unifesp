#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define ERROR_CONNECTION "Error on try connect on server\n"
#define SUCCESS_CONNETION "Conect on server"
#define ERROR_SOCKET "Error on create socker"
#define SUCESS_SOCKET "Socket create"
#define SUCESS_DISCONECT "Bye"
#define ERROR_DATA "Error on recieve data"


int main(int argc, char **argv){

	int clientSocket, ret;
	struct sockaddr_in serverAddr;
	char buffer[1024], port, address;

    if(argc != 3) { 
        printf("Use: %s <porta> <endereço server>\n", argv[0]);
    }

    //SOCKET

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
        perror(ERROR_SOCKET);
		exit(1);
	}
	printf(SUCESS_SOCKET);


    //CONNECT

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(atoi(argv[1]));
	serverAddr.sin_addr.s_addr = inet_addr(argv[2]);

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
        perror(ERROR_CONNECTION);
		exit(1);
	}
	printf(SUCCESS_CONNETION);
    
	while(1){
        // WRITE
		printf("Client says: \t");
		scanf("%s", &buffer[0]);
		send(clientSocket, buffer, strlen(buffer), 0);

		if(strcmp(buffer, "exit") == 0){
			close(clientSocket);
			printf(SUCCESS_CONNETION);
			exit(1);
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