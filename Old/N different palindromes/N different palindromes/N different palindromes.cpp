// N different palindromes.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/SNCKPA16/problems/NDIFFPAL

#include <stdio.h>


int main()
{
	int T, i, N;
	char ip[27] = "abcdefghijklmnopqrstuvwxyz";
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		while (N >= 26)
		{
			printf("%s", ip);
			N -= 26;
		}
		for (i = 0;i < N;i++)
		{
			printf("%c", ip[i]);
		}
		printf("\n");
	}
	return 0;
}

