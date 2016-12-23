// Paint The Tiles.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/hourrank-7/challenges/tile-painting

#include <stdio.h>


int main()
{
	int N, i = 1, ans = 1;
	char ip[1001];
	scanf("%d%s", &N, ip);
	while (ip[i] != '\0')
	{
		if (ip[i] != ip[i - 1])
		{
			ans++;
		}
		i++;
	}
	printf("%d\n", ans);
	return 0;
}

