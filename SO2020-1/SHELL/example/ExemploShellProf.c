#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

//função fork() retorna um pid_t que é um inteiro e não precisa passar parametro nela

int main(int argc, char **argv)
{
    pid_t pid;
    
    if(argc == 1)
    {
        printf("Uso: %s <comando> <p_1> <p_2> ... <p_n>\n", argv[0]);
        return 0;
    }

    pid = fork();
    if(pid == 0) //processo filho: executa o comando
    {   
        char **cmd;
        cmd = &argv[1];
        execvp(cmd[0], cmd);
    }
    else if(pid > 0) //processo pai: aguarda o termino do filho
    {
        int status;
        waitpid(-1, &status, 0);
    }
    else //erro
    {
        perror("fork()");
        return -1;
    }
    return 0;
}