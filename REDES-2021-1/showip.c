#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

void *get_in_addr (struct addrinfo *p) {
    /* IPv4 */
    struct sockaddr_in *ipv4 = (struct sockaddr_in *) p->ai_addr;
    return &(ipv4->sin_addr);

}

void get_address (struct addrinfo *response, char straux[]) {
    struct addrinfo *p;
    char ipstr[INET_ADDRSTRLEN];


    for(p = response; p != NULL; p = p->ai_next)
        if (p->ai_family == AF_INET) {
            inet_ntop(p->ai_family, get_in_addr(p), ipstr, sizeof ipstr);
            break;
        }

    strcpy(straux, ipstr);
}

int main (int argc, char **argv) {
    struct addrinfo request;
    struct addrinfo *response;
    int status;
    char ipstr[INET_ADDRSTRLEN];

    if (argc != 2) {
        printf("USAGE:./FILE-NAME <FQDN> <PORT>");
        return EXIT_FAILURE;
    }

    memset(&request, 0, sizeof request); // Zerando a memória

    request.ai_family = AF_UNSPEC; // Nesse caso, qualquer um dos dois
    request.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(argv[1], NULL, &request, &response);

    if (status != 0) {
        fprintf(stderr, "getaddrinfo failure: %s\n", gai_strerror(status));
        return EXIT_FAILURE;
    }

    get_address(response, ipstr);

    printf("IP-SERVIDOR: %s\n", ipstr);

    freeaddrinfo(response);

    return EXIT_SUCCESS;
}