#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node
{
	struct Node * left, * right;
	int data;
}Node;

Node * newNode(int data)
{
	Node *n=(Node *)malloc(sizeof(Node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;

	return n;
}


Node * findMax(Node *n)
{
	if(n==NULL)
	{
		return NULL;
	}
	else if(n->right !=NULL)
	{
		return findMax(n->right);
	}

	return n;
}


Node * findMin(Node *n)
{
	if(n==NULL)
	{
		return NULL;
	}
	else if(n->left !=NULL)
	{
		return findMin(n->left);
	}

	return n;
}

void delete(Node *node)
{
	if(node==NULL) return;

	delete(node->left);
	delete(node->right);
	free(node);
}

int main()
{
	printf("\nInserting nodes into the BST\n");
	Node * root = newNode(5);
	root->left=newNode(3);
	root->right=newNode(8);
	root->left->left = newNode(2);
	root->left->right = newNode(4);
	root->right->left = newNode(6);
	root->right->right = newNode(9);
	root->left->left->left = newNode(1);
	root->right->left->right = newNode(7);
	
	//printf("Test3");

	
	Node * maxtemp = findMax(root);

	//printf("Test5");

	printf("\nMaximum element in Tree is %d\n",maxtemp->data);
	
	Node * mintemp = findMin(root);
	
	printf("\nMinimum element in Tree is %d\n\n",mintemp->data);
	
	delete(root);

	return 0;
}



