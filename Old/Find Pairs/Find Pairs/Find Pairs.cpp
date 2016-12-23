// Find Pairs.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType
{
	long data;
	long count;
	struct nodeType *left, *right;
} node;

long count;


node* buildTree(node* root, long data)
{
	if (root == NULL)
	{
		node *newNode = (node*)malloc(sizeof(node));
		newNode->data = data;
		newNode->count = 1;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else
	{
		if (data < root->data)
		{
			root->left = buildTree(root->left, data);
		}
		else if (data > root->data)
		{
			root->right = buildTree(root->right, data);
		}
		else
		{
			root->count++;
		}
		return root;
	}
}


void traverse(node *root)
{
	if (root != NULL)
	{
		traverse(root->left);
		count += (root->count)*(root->count + 1) / 2;
		traverse(root->right);
	}
}


void cutTree(node *root)
{
	if (root != NULL)
	{
		cutTree(root->left);
		cutTree(root->right);
		free(root);
	}
}




int main()
{
	int T;
	long N, data;
	node *root = NULL;
	scanf("%d", &T);
	while (T--)
	{
		count = 0;
		scanf("%ld", &N);
		while (N--)
		{
			scanf("%ld", &data);
			root = buildTree(root, data);
		}
		traverse(root);
		cutTree(root);
		printf("%ld\n", count);
		root = NULL;
	}
	return 0;
}

