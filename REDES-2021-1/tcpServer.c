#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define ERROR_CONNECTION "Error on try connect on client\n"
#define SUCCESS_CONNETION "Conect on client\n"
#define ERROR_SOCKET "Error on create socker\n"
#define SUCESS_SOCKET "Socket create\n"
#define SUCESS_DISCONECT "Bye\n"
#define ERROR_DATA "Error on recieve data\n"
#define ERROR_BIND "Error on bind\n"
#define SUCESS_BIND "Sucess bind\n"
#define WAITING_CLIENTE "Waiting response for client\n"

int main(int argc, char **argv){

	int sockfd, ret;
	struct sockaddr_in serverAddr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	char buffer[1024];
	pid_t childpid;

    if(argc != 3) { 
        printf("Use: %s <porta> <endereço server>\n", argv[0]);
    }

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
        perror(ERROR_SOCKET);
		exit(1);
	}
	printf(SUCESS_SOCKET);

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(atoi(argv[1]));
	serverAddr.sin_addr.s_addr = inet_addr(argv[2]);

	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
        perror(ERROR_BIND);
		exit(1);
	}

	if(listen(sockfd, 10) == 0){
		printf(WAITING_CLIENTE);
	}


	while(1){
		newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if(newSocket < 0){
			exit(1);
		}
		printf("Connection accepted from %s---%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));

		if((childpid = fork()) == 0){
			close(sockfd);

			while(1){
				recv(newSocket, buffer, 1024, 0);
				if(strcmp(buffer, "exit") == 0){
					printf("Disconnected from %s---%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
					break;
				}else{
					printf("Client say: %s\n", buffer);
					send(newSocket, buffer, strlen(buffer), 0);
					bzero(buffer, sizeof(buffer));
				}
			}
		}

	}

	close(newSocket);


	return 0;
}