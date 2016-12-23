// Spirals.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
int main()
{
	int t,n,i,j,k;
	char s0[200],s1[200];
	for (i = 0; i < 199; i++)
	{
		s0[i] = '*';
		s1[i] = ' ';
	}
	s0[i] = s1[i] = '\0';
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);
		s0[n] = s1[n] = '\0';
		s1[0] = s1[n - 1] = '*';
		s1[0] = s1[n - 1] = '*';
		for (j = 0; j < n / 2 + 1; j++)
		{
			if (j % 2 == 0)
			{
				k = 0;
				while (s0[k]!='\0')
				{
					if (s0[k] == ' ')
						printf("  ");
					else
						printf("* ");
					k++;
				}
				printf("\n");
				s0[j + 1] = s0[n - 1 - (j + 1)] = ' ';
			}
			else
			{
				k = 0;
				while (s1[k] != '\0')
				{
					if (s1[k] == ' ')
						printf("  ");
					else
						printf("* ");
					k++;
				}
				printf("\n");
				s1[j + 1] = s1[n - 1 - (j + 1)] = '*';
			}
		}
		for (; j < n-1; j++)
		{
			if (j % 2 == 0)
			{
				s1[n - (j + 1)] = ' ';
				k = 0;
				while (s1[k] != '\0')
				{
					if (s1[k] == ' ')
						printf("  ");
					else
						printf("* ");
					k++;
				}
				printf("\n");
				s1[j] = ' ';
			}
			else
			{
				s0[n - (j + 1)] = '*';
				s0[j-2] = '*';
				k = 0;
				while (s0[k] != '\0')
				{
					if (s0[k] == ' ')
						printf("  ");
					else
						printf("* ");
					k++;
				}
				printf("\n");
			}
		}
		printf("\n");
		s0[n - 2] = s0[n] = '*';
		s1[0] = s1[n - 1]= s1[n] = ' ';
	}
	return 0;
}