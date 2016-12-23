// Cavity Map.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int n, i, j;
	char map[100][101];

	scanf("%d", &n);
	for (i = 0;i < n;i++)
	{
		scanf("%s", map[i]);
	}

	for (i = 1;i < n - 1;i++)
	{
		for (j = 1;j < n - 1;j++)
		{
			if(map[i-1][j]!='X')
				if (map[i][j]>map[i - 1][j] && map[i][j]>map[i + 1][j] && map[i][j]>map[i][j - 1] && map[i][j] > map[i][j + 1])
				{
					map[i][j] = 'X';
					j++;
				}
		}
	}
	for (i = 0;i < n;i++)
	{
		printf("%s\n", map[i]);
	}


	return 0;
}

