#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define PORT 4444


int main() {
    int sockfd, ret;
    struct sockaddr_in serverAddr;
    int newSocket;
    struct sockaddr_in newAddr;
    char buffer[1024];
    pid_t childpid;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(socket < 0) {
        printf("Error");
        exit(1);
    }

    printf("Server create");

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    if(ret < 0) {
        printf("Error");
        exit(1);
    }

    printf("BINDOU na porta");

    if(listen(sockfd, 10) == 0) {
        printf("Escutou\n");
    } else {
        printf("Error");
        exit(1);
    }

    while (1) {
        newSocket = accept(sockfd, (struct sockaddr*)&newAddr, sizeof(newAddr));
        if (newSocket < 0) {
            printf("Error");
            exit(1);
        }
        printf("Conectionzou");

        if ((childpid = fork()) == 0) {
            close(sockfd);
            while (1){
                recv(newSocket, buffer, 1024,0);
                if(strcmp(buffer, "exit") == 0) {
                    printf("Disconect");
                    break;
                } else {
                    printf("CLient: %s\n", buffer);
                    send(newSocket, buffer, strlen(buffer), 0);
                    bzero(buffer, sizeof(buffer));
                }
            }
            
        }
    }

    close(sockfd);


}