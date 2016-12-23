// Punit and Patterns.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, n, arr[4][4], i, j = 0, k = 0;
	int cse = 0;


	for (i = 1;i <= 10;i++)
	{
		arr[j][k] = i;
		printf("%d\n", cse);
		switch (cse)
		{
		case 0:
			k = k + 1;
			cse = 1;
			break;
		case 1:

			if (k==0)
			{
				cse = 2;
			}
			else
			{
				k--;
			}
			j = j + 1;

			break;
		case 2:
			j = j + 1;
			cse = 3;
			break;
		case 3:
			if (j == 0)
			{
				cse = 0;
				
			}
			else
			{
				j = j - 1;
			}
			k++;
			break;
		}
	}

	for (i = 0;i < 4;i++)
	{
		for (j = 0;j < 4;j++)
		{
			printf("%d ", arr[i][j]);
		}
	}
	/*
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		i = j = 0;
		while (arr[i][j] <= n)
		{
			j = 0;
			while (arr[i][j] <= n)
			{
				printf("%d ", arr[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}

	}
	*/

	return 0;
}

