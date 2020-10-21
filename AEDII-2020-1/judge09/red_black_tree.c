#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

typedef struct Node * tree;

struct  Node {
    int data;
    struct Node *left;
    struct Node *right;
    int color;
};

int color(struct Node* H) {
    if (H == NULL) {
        return BLACK;
    } else {
        return H->color;
    } 
}

void changeColor(struct Node* H) {
    H->color = !H->color;
    if (H->left != NULL) {
        H->left->color = !H->left->color;
    } 

    if (H->right != NULL) {
        H->right->color = !H->right->color;
    }
}

struct Node* rotateLeft(struct Node * A) {
    struct Node * B = A->right;
    A->right = B->left;
    B->left = A;
    B->color = A->color;
    A->color = RED;
    return B;
}


struct Node* rotateRight(struct Node * A) {
    struct Node * B = A->left;
    A->left = B->right;
    B->right = A;
    B->color = A->color;
    A->color = RED;
    return B;
}

struct Node* move2LeftRED(struct Node * H) {
    changeColor(H);
    if (color(H->right->left) == RED) {
        H->right = rotateRight(H->right);
        H = rotateLeft(H);
        changeColor(H);
    }
    return H;
}

struct Node* move2RightRED(struct Node * H) {
    changeColor(H);
    if (color(H->left->left) == RED) {
        H = rotateRight(H);
        changeColor(H);
    }
    return H;
}


struct Node* balance(struct Node* H){
    if(color(H->right) == RED){
        H = rotateLeft(H);
    }

    if(H->left != NULL && color(H->right) == RED && color(H->left->left) == RED){
        H = rotateRight(H);
    }
    if(color(H->left) == RED && color(H->right) == RED){
        changeColor(H);
    }

    return H;
}
int main () {
    tree* head;
}

