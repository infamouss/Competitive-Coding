// Project Euler 22 Names scores.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct nodeType
{
	struct nodeType *left, *right;
	int no;
	char name[13];
} node;

int num;

node* buildTree(node* root, char name[])
{
	if (root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		strcpy(root->name, name);
		root->left = root->right = NULL;
	}
	else
	{
		if (strcmp(root->name, name) > 0)
		{
			root->left = buildTree(root->left, name);
		}
		else
		{
			root->right = buildTree(root->right, name);
		}
	}
	return root;
}

void inorder(node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		++num;
		root->no = num;
		inorder(root->right);
	}
}

long search(node* root,char name[])
{
	long ans = 0;
	if (root != NULL)
	{
		if (strcmp(root->name, name) == 0)
		{
			int i = 0;
			while (name[i] != '\0')
			{
				ans += name[i] + 1 - 'A';
				i++;
			}
			ans *= root->no;
		}
		else if (strcmp(root->name, name) > 0)
		{
			ans = search(root->left , name);
		}
		else
		{
			ans = search(root->right , name);
		}
	}
	return ans;
}

void cutTree(node* root)
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
	node *root = NULL;
	int N, Q, i;
	char name[13];
	scanf("%d%d", &N);
	for (i = 0;i < N;i++)
	{
		scanf("%s", name);
		root = buildTree(root, name);
	}
	num = 0;
	inorder(root);
	scanf("%d", &Q);
	for (i = 0;i < Q;i++)
	{
		scanf("%s", name);
		printf("%ld\n", search(root, name));
	}
	cutTree(root);
	root = NULL;
	return 0;
}

