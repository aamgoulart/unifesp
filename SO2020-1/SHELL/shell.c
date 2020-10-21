#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv){
    pid_t pid;
    //se a pessoa colocou só o "./shell" retorna uma msg de erro pra ela
    if(argc == 1){
        printf("Uso: %s <comando> <p_1> <_p_2> ... <p__n>\n"argv[0]);
        return 0;
    }
    //cria um novo processo e coloca o PID dele em uma variavel
    pid = fork();
    if(pid == 0){//processo filho executa o comando
	//cria um vetor pra armazenar a string que veio do terminal
        char **cmd;
	//retira o "argv[0]" que seria o "./shell"
        cmd = &argv[1];
	//procura e executa o comando
        execvp(cmd[0],cmd);
    }else if (pid > 0){//processo pai espera termino do filho
        int status;
        waitpid(-1, &status, 0);
    }else{//erro
        perror("fork()");
        return -1;
    }
    return 0;
}
