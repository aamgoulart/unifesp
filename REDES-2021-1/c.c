#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

int main () {
    int clientSocket, ret;
    struct  sockaddr_in serverAddr;
    char buffer[1024];

    clientSocket = socket(AF_INET, SOCK_STREAM,0);
    if(clientSocket <0) {
        printf("Error");
        exit(1);
    }

    printf("Cliente socket create!");

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    
    if(ret < 0) {
        printf("Error");
        exit(1);
    }

    printf("Conectado!");

    while (1) {
        printf("Client: \t");
        scanf("%s", &buffer[0]);
        send(clientSocket, buffer, strlen(buffer), 0);

        if(strcmp(buffer, "exit") == 0) {
            printf("Disconnect");
            exit(1);
        }

        if(recv(clientSocket, buffer, 1024, 0) < 0) {
            printf("Error data");
        } else {
            printf("Server: \t %s\n", buffer);
        }
    }
    

}
