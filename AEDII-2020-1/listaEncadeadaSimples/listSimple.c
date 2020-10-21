#include <stdlib.h>
#include <stdio.h>

struct listNode {
    int value;
    struct listNode *next;
} typedef listNode;


struct listSimple {
    listNode *init;
} typedef listSimple;

void initList(listSimple *list){
    list->init = NULL;
}

void add(listSimple *list, int value){
    listNode *newNode = malloc(sizeof(listNode));
    newNode->value = value;
    

    if (list->init == NULL){ // in case the list has empty
        list->init = newNode;
        newNode->next = NULL;
    } else {
        listNode *findNode = list->init;
        listNode *aux;


        while(findNode != NULL && value > findNode->value){
            aux = findNode;
            findNode = findNode->next;
        }

        if (findNode == NULL){ // in case the insertion in last 
            aux->next = newNode;
            newNode->next = NULL;
        } else if (findNode == list->init) {
            list->init = newNode;
            newNode->next = NULL;

        } else { // in case the insertion in the minddle of list
            newNode->next = aux->next;
            aux->next = newNode;
        }
    }
}

void output(listSimple *list){
    listNode *walks = list->init;
    while(walks != NULL){
        printf("%d\n", walks->value);
        walks = walks->next;
    }
}


void delete (listSimple *list, int value){
 listNode *findNode = list->init;
 listNode *aux;
 while(findNode != NULL){ 
   if (findNode->value == value){ 
     aux->next = findNode->next; 
     free(findNode); 
}
   aux = findNode;
   findNode = findNode->next;
   }
}



int main (){
    listSimple list;
    int number[10] = {1,6,3,5,8,9,10,2,4,7}, i;

    initList(&list);
    for (i=0;i<10;i++){
        add(&list,number[i]);
    }
    output(&list);

}