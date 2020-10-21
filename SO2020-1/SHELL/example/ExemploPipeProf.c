#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define STR_LEN 100

//função fork() retorna um pid_t que é um inteiro e não precisa passar parametro nela

int main(int argc, char **argv)
{
    int fd[2], ch_fd[2];
    pid_t child;

    if(pipe(fd) < 0)
    {
        perror("pipe()");
        return -1;
    }

    if(pipe(ch_fd) < 0)
    {
        perror("pipe(ch_fd)");
        return -1;
    }

    child = fork();

    if(child == 0) //filho le no 0
    {
        char msg[STR_LEN];
        close(fd[1]);
        close(ch_fd[0]);
        bzero(msg, STR_LEN);
        if(read(fd[0], msg, STR_LEN) > 0)
        {
            printf("Filho (PID=$%ld) leu: '%s'\n", (long)getpid(), msg);
        }
        bzero(msg, STR_LEN);
        sprintf(msg, "Ok, papai!");
        write(ch_fd[1], msg, strlen(msg));
        printf("Filho terminando... Dormindo 5s. \n");
        sleep(5);
    }
    else //pai escreve no 1
    {
        char pa_msg[STR_LEN];
        int status;
        close(fd[0]);
        close(ch_fd[1]);
        bzero(pa_msg, STR_LEN);
        printf("Pai (PID=%ld) escrevendo para o filho...\n", (long)getpid());
        sprintf(pa_msg, "Filho, preste atencao!.\n");
        write(fd[1], pa_msg, strlen(pa_msg));
        bzero(pa_msg, STR_LEN);
        read(ch_fd[0], pa_msg, STR_LEN);
        printf("Pai leu: '%s'\n", pa_msg);
        waitpid(-1, &status, 0);
        printf("Pai: Filho terminou... \n");
    }
    return 0;
}