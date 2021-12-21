#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define REQ_GET "GET"
#define COD_RESP_GET_OK "GET OK"
#define COD_ERROR "ERROR"

struct req_t
{
    char method[128];
    char filename[256];
};

typedef struct req_t req_t;

void get_request(req_t *r, char *rstr) {
    bzero(r, sizeof(req_t));
    sscanf(rstr, "%s %s", r->method, r->filename);
}

void proc_request(int sockfd, req_t r) {
    if (strcmp(r.method, REQ_GET) == 0) {
        send(sockfd, COD_RESP_GET_OK, strlen(COD_RESP_GET_OK),0);
    } else {
        send(sockfd, COD_ERROR, strlen(COD_ERROR), 0);
    }
}

// void send_file(int sockfd, req_t r) {
//     int fd;
//     fd = open(r.filename)
// }

int main(int argc, char **argv) {

    if(argc != 2) { // verifica se o usuario passou a porta. O lado do servidor precisa da porta, 
    //mas o lado do cliente precisa do endereço  e porta
        printf("Use: %s <porta>\n", argv[0]);
    }

    // PARTE SOCKET 

    int sl;
    sl = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // cria um endpoint para a comunicação,parans DOMINIO, TIPO e PRONTOCOLO

    if(sl == -1) { //verifica o erro da criação
        perror("socket");
        return 0;
    }

    // PARTE LISTEN
    // vincula a porta , o endepreço IP e o tamanho do endereçamento
    struct sockaddr_in saddr;
    saddr.sin_port = htons(atoi(argv[1])); // porta
    saddr.sin_family = AF_INET; // familia
    saddr.sin_addr.s_addr = INADDR_ANY; // endereço IP nesse caso vai para todos os IPs da maquina

    if(bind(sl, (struct sockaddr_in *)&saddr,
            sizeof(struct sockaddr_in)) == -1) {
                perror("bind");
                return 0;
    }

    if(listen(sl, 1000) == -1) {
        perror("listen");
        return 0;
    }    


    // PARTE ACCEPT
    struct sockaddr_in caddr;
    int sc, nr;
    int addr_len;
    #define  MAX_REQ_LEN 1000
    char request[MAX_REQ_LEN];


    
    while(1) {
        addr_len = sizeof(struct sockaddr_in);
        sc = accept(sl, (struct sockaddr_in *)&caddr, (socklen_t*)&addr_len); //socket cliente, tenta a conexao com o cliente
        if (sc == -1) {
            perror("accept");
            continue;
        }
        printf("Conectado com o cliente");
        bzero(request, MAX_REQ_LEN); // limpa a request
        // PARTE RECIEVE
        nr = recv(sc, request, MAX_REQ_LEN, 0); // recebe a request

        if(nr > 0) {
            printf("%s\n", request);
        }
        close(sc); // uma requisição por vez 
    }
    close(sc);
}