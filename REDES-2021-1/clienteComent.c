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
        printf("Use: %s <porta> <endereço server>\n", argv[0]); // tratamento de erro, caso usuario não utilize corretamente 
    }

	hostname_to_ip(argv[2] , ip); // funçãoq que criamos para realizar a conversão do nome para o endereço de IP correto

    //SOCKET

	clientSocket = socket(AF_INET, SOCK_STREAM, 0); // cria um socket , passando o domain, tipo e  prontocolo  que etsamos fazendo, no TCP
	if(clientSocket < 0){ // tratamento de erro  
        perror(ERROR_SOCKET); 
		return EXIT_FAILURE;
	}
	printf(SUCESS_SOCKET);


    //CONNECT

	memset(&serverAddr, '\0', sizeof(serverAddr)); // realizar uma copia de ponteiro http://www.w3big.com/pt/cprogramming/c-function-memset.html

    // neste trecho setamos os valores basicos para o servidor, sendo eles a familia, porta e o endereço 
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(atoi(argv[1]));
	serverAddr.sin_addr.s_addr = inet_addr(ip);

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)); // aqui faz a conexão, passamos o client, o server que crianos e o tamanho dele de memoria
	if(ret < 0){ // tratamento de erro  
        perror(ERROR_CONNECTION);
		return EXIT_FAILURE;
	}
	printf(SUCCESS_CONNETION);
    
	while(1){ // aqui temos um laço infinito para ter a repetição de leitura e escrita do servidor, conforme o padrao da api sockets
        // WRITE
        memset(buffer,0,sizeof(buffer));
		printf("Client says: \t");
		gets(buffer); // pegamos o que o usuario quer enviar 
		send(clientSocket, buffer, strlen(buffer), 0); // e enviamos para a conexão criada o buffer modificado 

		if(strcmp(buffer, "exit") == 0){ // caso o usuario queira encerrar a conexão
			close(clientSocket);
			printf(SUCCESS_CONNETION);
			return EXIT_FAILURE;
		}

        // READ
        // neste caso o cliente esta lendo o que contém no buffer recebido da conexão com o servidor
		if(recv(clientSocket, buffer, 1024, 0) < 0){ 
			printf(ERROR_DATA);
		}else{
			printf("Server says: \t%s\n", buffer);
		}
	}

    close(clientSocket); // aqui fecha a conexão com o servidor

	return 0;
}

int hostname_to_ip(char * hostname , char* ip)
{
	struct hostent *he;
	struct in_addr **addr_list;
	int i;
		
	if ( (he = gethostbyname( hostname ) ) == NULL) // pega o name e tras uma estrutura que contem o ip dele -> https://pt.stackoverflow.com/questions/316543/codigo-em-c-url-inet-ntoastruct-in-addr-ip-h-addr-n%C3%A3o-entendo-o-que-est
	{
		perror(ERROR_CONVERT_HOSTNAME);
		return 1;
	}

	addr_list = (struct in_addr **) he->h_addr_list;
	
	for(i = 0; addr_list[i] != NULL; i++)  // aqui copia cada número do ip para a string
	{
		//Return the first one;
		strcpy(ip , inet_ntoa(*addr_list[i]) );
		return 0;
	}
	
	return EXIT_FAILURE;
}