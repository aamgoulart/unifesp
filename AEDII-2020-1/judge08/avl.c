#include "stdio.h"
#include "stdlib.h"

struct Node
{
	int data;
	int height;
	struct Node* left;
	struct Node* right;
};
//Insertion and deletion in AVL Tree
struct Node* NewNode(int data)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	temp->height = 1;
	return temp;
}

int max(int a,int b)
{
 	return (a>b)?a:b;
}

int height(struct Node* node)
{
	if(node==NULL)
		return 0;

 	return node->height;
}

int Balance(struct Node* node)
{
	if(node==NULL)
		return 0;

 	return height(node->left) - height(node->right);
}

struct Node* LeftRotate(struct Node* z)
{
	struct Node* y = z->right;
	struct Node* t2 = y->left;

	y->left = z;
	z->right = t2;

	z->height = max(height(z->left),height(z->right))+1;
	y->height = max(height(y->left),height(y->right))+1;

	return y;
}

struct Node* RightRotate(struct Node* z)
{
	struct Node* y = z->left;
	struct Node* t3 = y->right;

	y->right = z;
	z->left = t3;

	z->height = max(height(z->left),height(z->right))+1;
	y->height = max(height(y->left),height(y->right))+1;

	return y;
}

void preorder(struct Node* root)
{
	// if(root==NULL)
	// 	return;

    if (root != NULL) {
        printf("(C%d ",root->data);
        preorder(root->left);
        preorder(root->right);
        printf(")");
    } else {
		printf("()");
    }

}

struct Node* FindMin(struct Node* node)
{
	while(node->left!=NULL)
		node = node->left;

	return node;
}

struct Node* Delete(struct Node* root,int data)
{
	if(root==NULL)
		return root;

	if(data < root->data)
		root->left = Delete(root->left,data);

	else if(data > root->data)
		root->right = Delete(root->right,data);

	else
	{
		if(root->right==NULL && root->left==NULL)
		{
			free(root);
			root = NULL;
		}

		else if(root->left!=NULL && root->right==NULL)
		{
			struct Node* temp = root->left;
			root = root->left;
			free(temp);
		}

		else if(root->right!=NULL && root->left==NULL)
		{
			struct Node* temp = root->right;
			root = root->right;
			free(temp);
		}

		else
		{
			struct Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	if(root==NULL)
		return root;

	root->height = 1 + max(height(root->left),height(root->right));

	int balance = Balance(root);

	//Left Left Case
	if(balance > 1 && Balance(root->left) >=0)
		return RightRotate(root);

	// Right Right Case
	if(balance < -1 && Balance(root->right) <=0)
		return LeftRotate(root);

	// Left Right Case
	if(balance > 1 && Balance(root->left) < 0)
	{
		root->left = LeftRotate(root->left);
		return RightRotate(root);
	}
	
	//Right Left Case
	if(balance < -1 && Balance(root->right) > 0)
	{
		root->right = RightRotate(root->right);
		return LeftRotate(root);
	}
	return root;
}

struct Node* Insert(struct Node* root,int data)
{
	if(root==NULL)
		return NewNode(data);

	if(data < root->data)
		root->left = Insert(root->left,data);

	else if(data > root->data)
		root->right = Insert(root->right,data);

	else
		return root;

	root->height = max(height(root->left),height(root->right))+1;

	int balance = Balance(root);

	// Left Left Case
	if(balance > 1 && data < root->left->data)
		return RightRotate(root);

	// Right Right Case
	if(balance < -1 && data > root->right->data)
		return LeftRotate(root);

	//Left Right Case
	if(balance > 1 && data > root->left->data)
	{
		root->left = LeftRotate(root->left);
		return RightRotate(root);
	}

	// Right Left Case
	if(balance < -1 && data < root->right->data)
	{
		root->right = RightRotate(root->right);
		return LeftRotate(root);
	}

	return root;
}

struct Node* buscaABB (struct Node* meuNo, int f){

    if (meuNo == NULL) {
        return NULL;
    } else if (meuNo->data > f) {
        return buscaABB(meuNo->left, f);
    } else if (meuNo->data < f) {
        return buscaABB(meuNo->right, f);
    } else {
        return meuNo;
    } 
}

int main()
{
	struct Node* root = NULL;
    struct Node*busca;

    int sizeNodes, findNode,i, node;

    scanf("%d", &sizeNodes);

    for (i=0; i<sizeNodes; i++){
        scanf("%d", &node);
        root = Insert(root,node);

    }

    scanf("%d", &findNode);

    busca = buscaABB(root, findNode);

    if (busca == NULL) {
        root = Insert(root,findNode);
    } else if (busca->data == findNode) {
        root = Delete(root,findNode);
    }


    preorder(root);


	return 0;
}