// Print the pattern!.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
void printDiamond(int size, int num);

int main()
{
	int t,row,col,size,i,j,k;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d%d%d", &row, &col, &size);
		for (j = 0; j < row; j++)
			printDiamond(size, col);
		printf("\n");
		
	}
	return 0;
}


void printDiamond(int size,int num)
{
	int i, j, k;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < num; j++)
		{
			for (k = size -1 - i; k > 0; k--)
			{
				printf(".");
			}
			printf("/");
			for (k = 0; k < i; k++)
			{
				printf("**");
			}
			printf("\\");
			for (k = size -1 - i; k > 0; k--)
			{
				printf(".");
			}
		}
		printf("\n");
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < num; j++)
		{
			for (k = 0; k < i; k++)
			{
				printf(".");
			}
			printf("\\");
			for (k = 1; k < size-i; k++)
			{
				printf("*");
			}
			for (k = 1; k < size - i; k++)
			{
				printf("*");
			}
			printf("/");
			for (k = 0; k < i; k++)
			{
				printf(".");
			}
		}
		printf("\n");
	}
}


