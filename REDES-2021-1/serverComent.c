#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>	

#define ERROR_CONNECTION "Error on try connect on client\n"
#define SUCCESS_CONNETION "Conect on client\n"
#define ERROR_SOCKET "Error on create socker\n"
#define SUCESS_SOCKET "Socket create\n"
#define SUCESS_DISCONECT "Bye\n"
#define ERROR_DATA "Error on recieve data\n"
#define ERROR_BIND "Error on bind\n"
#define SUCESS_BIND "Sucess bind\n"
#define WAITING_CLIENTE "Waiting response for client\n"
#define ERROR_CONVERT_HOSTNAME "Error on convert hostname to ip address"

int hostname_to_ip(char * hostname , char* ip);

int main(int argc, char **argv){

	int sockfd, ret;
	struct sockaddr_in serverAddr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	char buffer[1024];
	pid_t childpid;

	char ip[100];

    if(argc != 3) { 
        printf("Use: %s <porta> <endereço server>\n", argv[0]); // tratamento de erro, caso usuario não utilize corretamente 
    }

	hostname_to_ip(argv[2] , ip); // funçãoq que criamos para realizar a conversão do nome para o endereço de IP correto

	sockfd = socket(AF_INET, SOCK_STREAM, 0); // cria um socket , passando o domain, tipo e  prontocolo  que etsamos fazendo, no TCP
	if(sockfd < 0){  // tratamento de erro  
        perror(ERROR_SOCKET);
		return EXIT_FAILURE;
	}
	printf(SUCESS_SOCKET);

	memset(&serverAddr, '\0', sizeof(serverAddr)); // realizar uma copia de ponteiro http://www.w3big.com/pt/cprogramming/c-function-memset.html
	
    // neste trecho setamos os valores basicos para o servidor, sendo eles a familia, porta e o endereço 
    serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(atoi(argv[1]));
	serverAddr.sin_addr.s_addr = inet_addr(ip);

	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)); //. Este é o endereço onde os pacotes são recebidos. Os pacotes enviados pelo socket carregam isso como o endereço de origem, de modo que o outro host saberá para onde enviar seus pacotes. 
	if(ret < 0){
        perror(ERROR_BIND);
		return EXIT_FAILURE;
	}

	if(listen(sockfd, 10) == 0){ // prepara a conexão para o cliente
		printf(WAITING_CLIENTE);
	}


	while(1){
		newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size); // aguarda a conexão do cliente
		if(newSocket < 0){
			return EXIT_FAILURE;
		}
		printf("Connection accepted from %s---%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));

		if((childpid = fork()) == 0){ // duplico o proceso para receber mais clientes
			close(sockfd);

			while(1){
				recv(newSocket, buffer, 1024, 0);    // neste caso o server esta lendo o que contém no buffer recebido da conexão com o cliente

				if(strcmp(buffer, "exit") == 0){ // caso o usuario queira encerrar a conexão
					printf("Disconnected from %s---%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
					break;
				}else{
					printf("Client %d say: %s\n",  ntohs(newAddr.sin_port), buffer);
                    memset(buffer,0,sizeof(buffer));
                    printf("Server says: \t");
                    bzero(buffer, sizeof(buffer));
                    gets(buffer); // pegamos o que o usuario quer enviar 
					send(newSocket, buffer, strlen(buffer), 0); 
				}
			}
		}

	}

	close(newSocket);


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
		return EXIT_FAILURE;
	}

	addr_list = (struct in_addr **) he->h_addr_list;
	
	for(i = 0; addr_list[i] != NULL; i++) 
	{
		strcpy(ip , inet_ntoa(*addr_list[i]) );
		return 0;
	}
	
	return EXIT_FAILURE;
}