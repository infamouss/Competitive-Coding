// Monk and his Friends.cpp : Defines the entry polong long for the console application.
//

#include <stdio.h>
#include <stdlib.h>



typedef struct  nodeTag
{
	struct nodeTag *left, *right;
	long long data;
} node;


node* searchInsert(node* root, long long data, int *flag)
{
	if (root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root->left = root->right = NULL;
		root->data = data;
		*flag = 1;
	}
	else if (root->data == data)
	{
		*flag = 0;
	}
	else if (data < root->data)
	{
		root->left = searchInsert(root->left, data, flag);
	}
	else
	{
		root->right = searchInsert(root->right, data, flag);
	}
	return root;
}

void delTree(node* root)
{
	if (root != NULL)
	{
		delTree(root->left);
		delTree(root->right);
		free(root);
	}
}



int main()
{
	long N, M, i;
	long long data;
	int t, flag;
	scanf("%d", &t);
	node *root = NULL;
	while (t--)
	{
		scanf("%ld%ld", &N, &M);
		for (i = 0;i < N;i++)
		{
			scanf("%lld", &data);
			root = searchInsert(root, data, &flag);
		}
		for (i = 0;i < M;i++)
		{
			flag = 0;
			scanf("%lld", &data);
			root = searchInsert(root, data, &flag);
			if (flag == 1)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
			}
		}
		delTree(root);
		root = NULL;
	}
	return 0;
}