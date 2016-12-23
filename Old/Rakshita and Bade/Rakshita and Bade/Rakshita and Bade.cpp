// Rakshita and Bade.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/holi-code/challenges/rakshita-and-bade
// Concept used : NIM game algorithm

#include <stdio.h>


long islands[500000];

int main()
{
	int T, decided;
	long i, numIslands;
	char ip[1000001];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", ip);
		i = numIslands = 0;
		while (ip[i] != '\0')
		{
			if (ip[i] == '1')
			{
				islands[numIslands] = 0;
				while (ip[i] == '1')
				{
					i++;
					islands[numIslands]++;
				}
				i--;
				numIslands++;
			}
			i++;
		}
		decided = 0;
		for (i = 0;i < numIslands;i++)
		{
			decided = decided^islands[i];
		}
		if (decided != 0)
		{
			printf("Rakshita\n");
		}
		else
		{
			printf("Bade\n");
		}
	}
	return 0;
}

