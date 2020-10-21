#include <stdio.h>
#include <string.h>
#define TAM 100

// ESTRUTURA
struct agenda {
    int numero;
    char nome[TAM];
};

// DECLARACAO DAS FUNCOES
void limpa_agenda (struct agenda amigo[TAM]);
void cadastro (struct agenda amigo[TAM]);
void lista (struct agenda amigo[TAM]);
void mostra_contato(struct agenda amigo[TAM]);
void apaga_numero (struct agenda amigo[TAM]);
void apaga_nome (struct agenda amigo[TAM]);
int testa_numero(int indice, struct agenda amigo[TAM]);

//FUNCAO PRINCIPAL
int main (){
    int menu=10;
    struct agenda amiguinho[TAM];

    // LIMPA A AGENDA PARA NÃO CONTER LIXO DE MEMORIA
    limpa_agenda(amiguinho);

    // MENU DE OPCOES
    while (menu != 0){
        printf ("Escolha valores entre 0 e 5!\n");
        scanf("%d", &menu);
        switch(menu){
        
        case 1:
        cadastro (amiguinho);
        break;

        case 2:
        lista(amiguinho);
        break;

        case 3:
        mostra_contato(amiguinho);
        break;

        case 4:
        apaga_numero(amiguinho);
        break;

        case 5:
        apaga_nome(amiguinho);
        break;
        }
    } 
        printf("Tchau!");
        return 0;
    
}


// CADASTRO DE CONTATO
void cadastro (struct agenda amigo[TAM]){
    int i, lugar, rest, aux, qtd_digitos;

    struct agenda amiguinho[TAM];

    scanf ("%d", &lugar);
    
    if (lugar>100 || lugar<0){
        printf ("Indice digitado nao existe [1,100]!\n");
    } else{
        scanf ("%d", &amigo[lugar].numero);
        scanf ("%s", amigo[lugar].nome);
    }

    qtd_digitos= testa_numero(lugar, amiguinho);


    if (qtd_digitos>11 || qtd_digitos<10){
        printf ("Telefone deve não tem 10 ou 11 digitos! Favor digite novamente.\n");
        cadastro(amiguinho);
    } else {
        printf ("Contato cadastrado com sucesso!\n");
    }
}

// IMPRIME TODA A AGENDA
void lista (struct agenda amigo[TAM]){
    int i;

    for (i=0; i<TAM; i++){
        printf ("Contato[%d]- Nome:%s Tel:%d\n", i+1, amigo[i].nome, amigo[i].numero);
    }
}

// MOSTRA DETERMINADO CONTATO
void mostra_contato(struct agenda amigo[TAM]){
    int lugar,i;

    scanf ("%d", &lugar);

    for (i=0; i<TAM; i++){
        if (amigo[i].nome[i] != '\0' || amigo[i].numero != 0){
            if (amigo[lugar].nome[i] == '\0' || amigo[lugar].numero == 0){
                printf("Contato digitado nao existe!\n");
            }

            if (lugar<1 || lugar > 100){
                printf ("Indice digitado nao existe [1,100]!\n");
            } else {
                printf ("Contato[%d]- Nome:%s Tel:%d\n", lugar+1, amigo[lugar].nome, amigo[lugar].numero);
            }
        } else {
            printf ("Agenda vazia!\n");
            break;
        }
    }  
}

// TIRA O LIXO DA AGENDA 
void limpa_agenda(struct agenda amigo[TAM]){
    int i;

    for (i=0; i<TAM; i++){
        amigo[i].nome[i]='\0';
        amigo[i].numero=0;
    }
}

// RECEBE O INDICE E APAGA O CONTATO
void apaga_numero (struct agenda amigo[TAM]){
    int lugar,i;
    scanf ("%d", &lugar);

    struct agenda amiguinho[TAM];

    for (i=0; i<TAM; i++){
        if (amigo[lugar].nome[i] == '\0' || amigo[lugar].numero == 0){
            printf ("Contato digitado nao existe!\n");
            break;
        } else if (lugar<1 || lugar > 100){
            printf ("Indice digitado nao existe [1,100]!\n");
            break;
         } else {
            amigo[lugar].nome[i]='\0';
            amigo[lugar].numero=0;
            printf ("Contato removido com sucesso!\n");
            lista(amiguinho);
        }
    }

    
}

// APAGA PELO NOME DO CONTATO
void apaga_nome (struct agenda amigo[TAM]){
    char name[TAM];
    int i;
    scanf ("%s", name);

    struct agenda amiguinho[TAM];

    for (i=0; i<TAM; i++){
        if (amigo[i].nome[i] == '\0'){
            printf ("Contato não existe\n");
            break;
        } else {
            amigo[i].nome[i]= '\n';
            amigo[i].numero=0;
            printf ("Contato removido com sucesso\n");
            lista(amiguinho);
        }
    }

    
}

// VERIFICA A QUANTIDADE DE DIGITOS 
int testa_numero(int indice, struct agenda amigo[TAM]){
    int rest, aux;
    rest = amigo[indice].numero;

    if (amigo[indice].numero==0){
        aux=1;
    }else {
        while(amigo[indice].numero>indice){
            rest=rest/10;
            aux++;
        }
    }
    return aux;
}
