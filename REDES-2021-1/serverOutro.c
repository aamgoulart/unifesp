#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

#define MAX_REQ_LEN 1000
#define FILE_BLOCK_SIZE 4000

#define REQ_GET "GET" 
#define REQ_CREATE "CREATE"
#define REQ_REMOVE "REMOVE"
#define REQ_APPEND "APPEND"

#define COD_OK_GET "OK-0 method GET OK\n"
#define COD_OK_APPEND "OK-1 method APPEND OK\n"
#define COD_OK_REMOVE "OK-2 method REMOVE OK\n"
#define COD_OK_CREATE "OK-3 method CREATE OK\n"
#define COD_ERROR_0_METHOD "ERROR-0 Method not supported\n"
#define COD_ERROR_1_FILE "ERROR-1 File couldn't be open\n"
#define COD_ERROR_2_FILE "ERROR-2 File couldn't be removed\n"
#define COD_ERROR_3_FILE "ERROR-2 File couldn't be created\n"
#define COD_OK1_FILE "OK-1 file opened\n"
#define COD_OK2_FILE "OK-2 file removed\n"
#define COD_OK3_FILE "OK-3 file created\n"

pthread_t thr[1000];

typedef struct req_t{
    char method[128];
    char filename[256];
    char text[616];
}req_t;

void get_request(req_t* r, char *rstr){
    bzero(r, sizeof(req_t));
    sscanf(rstr, "%s", r->method);  //get method

    if(strcmp(r->method, REQ_APPEND) == 0){
        sscanf(rstr, "%*s \"%5[^\"]\" %s", r->text, r->filename);    // get text and filename
    } else{
        sscanf(rstr, "%*s %s", r->filename);  //get filename
    }
    return;
}

void send_file(int sockfd, req_t r){
    int fd, nr;
    unsigned char fbuf[FILE_BLOCK_SIZE];

    fd = open(r.filename, O_RDONLY, S_IRUSR | S_IRGRP | S_IROTH);
    if(fd == -1){ //sem sucesso
        perror("open");
        send(sockfd, COD_ERROR_1_FILE, strlen(COD_ERROR_1_FILE), 0);
        return;
    }
    send(sockfd, COD_OK1_FILE, strlen(COD_OK1_FILE), 0);    // sucess

    // print file
    do{
        bzero(fbuf, FILE_BLOCK_SIZE);
        nr = read(fd, fbuf, FILE_BLOCK_SIZE);
        if(nr > 0){
            send(sockfd, fbuf, nr, 0);
        }
    }while(nr > 0);
    send(sockfd, "\n", 1, 0); // break line
    close(fd);

    return;
}

void edit_file(int sockfd, req_t r){
    int fd;
    fd = open(r.filename, O_RDWR | O_APPEND, S_IRWXU | S_IRWXO | S_IRWXG);
    if (fd == -1){
        perror("open");
        send(sockfd, COD_ERROR_1_FILE, strlen(COD_ERROR_1_FILE), 0);
        return;
    }
    send(sockfd, COD_OK1_FILE, strlen(COD_OK1_FILE), 0);
    write(fd, r.text, strlen(r.text));  // write in the file
    close(fd);
}

void remove_file(int sockfd, req_t r){
    int fd;
    fd = remove(r.filename);    // delete file
    if (fd == -1){
        perror("remove");
        send(sockfd, COD_ERROR_2_FILE, strlen(COD_ERROR_2_FILE), 0);
        return;
    }
    send(sockfd, COD_OK2_FILE, strlen(COD_OK2_FILE), 0);
    close(fd);
}

void create_file(int sockfd, req_t r){
    int fd;
    fd = creat(r.filename, S_IRWXU | S_IRWXO | S_IRWXG);    // open and create the file
    if (fd == -1){
        perror("create");
        send(sockfd, COD_ERROR_3_FILE, strlen(COD_ERROR_3_FILE), 0);
        return;
    }
    send(sockfd, COD_OK3_FILE, strlen(COD_OK3_FILE), 0);
    close(fd);
}


void proc_request(int sockfd, req_t r){
    if (strcmp(r.method, REQ_GET) == 0){        // GET
        send(sockfd, COD_OK_GET, strlen(COD_OK_GET), 0);
        send_file(sockfd, r);
    } else if (strcmp(r.method, REQ_APPEND) == 0){      // APPEND
        send(sockfd, COD_OK_APPEND, strlen(COD_OK_APPEND), 0);
        edit_file(sockfd, r);
    } else if (strcmp(r.method, REQ_REMOVE) == 0){      // REMOVE
        send(sockfd, COD_OK_REMOVE, strlen(COD_OK_REMOVE), 0);
        remove_file(sockfd, r);
    } else if (strcmp(r.method, REQ_CREATE) == 0){      // CREATE
        send(sockfd, COD_OK_CREATE, strlen(COD_OK_CREATE), 0);
        create_file(sockfd, r);
    } else 
        send(sockfd, COD_ERROR_0_METHOD, strlen(COD_ERROR_0_METHOD), 0);    //ERROR
    return;
}

struct arguments {
    int sc;
};

 
void *socket_connection(void *args) {
    struct arguments *arg = (struct arguments *) args;
    struct arguments argu = *arg;   // get the argument sc

    char request[MAX_REQ_LEN]; 
    req_t req;
    int nr;

    bzero(request, MAX_REQ_LEN);  
    // wait the input
    nr = recv(argu.sc, request, MAX_REQ_LEN, 0);
    if(nr > 0){
        get_request(&req, request);
        printf("method: %s, filename: %s\n", req.method, req.filename);
        proc_request(argu.sc, req);
    }

    close(argu.sc);
    pthread_exit(0);
}


int main(int argc, char* argv[]){
    // ./server <porta>
    if(argc != 2){
        printf("Use %s <porta>\n", argv[0]);
        return 0;
    }

    //socket
    //AF_INET -> IPv4
    //SOCK_STREAM -> protocolo TCP
    int sl;
    sl = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sl == -1){
        perror("socket");
        return 0;
    }

    struct sockaddr_in saddr;
    // captura o valor da porta passado por parametro
    saddr.sin_port = htons(atoi(argv[1])); 
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;

    //bind
    if(bind(sl, (struct sockaddr *)&saddr, 
        sizeof(struct sockaddr_in)) == -1){
            perror("bind");
            return 0;
    }

    //listen
    if (listen(sl, 1000) == -1){
        perror("listen");
        return 0;
    };

    struct sockaddr_in caddr;
    int addr_len;
    int sc; //server client
    int thrCounter = 0;
    int thrCaller;

    while(1){
        //accept
        addr_len = sizeof(struct sockaddr_in);
        sc = accept(sl, (struct sockaddr*)&caddr, (socklen_t *)&addr_len);

        //recv
        if(sc == -1){
            perror("accept");
            continue;       //em caso de erro, tenta nova conexão
        }
        printf("Conectado com cliente %s: na porta %d\n", inet_ntoa(caddr.sin_addr), ntohs(caddr.sin_port));

        struct arguments args;  // controi argumento da thread
        args.sc = sc;

        // chama thread
        thrCaller = pthread_create( &thr[thrCounter++], NULL , socket_connection, (void*)&args);
        if (thrCaller == -1){
            perror("thread\n");
        }
        if (thrCounter == 999) // reseta o contador de IDs de threads
            thrCounter = 0;
        
    }
    
    close(sl);
    return 0;
}