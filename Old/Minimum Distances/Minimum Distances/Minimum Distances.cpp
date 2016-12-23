// Minimum Distances.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/june-world-codesprint/challenges/minimum-distances

#include <stdio.h>


int main()
{
	int n, i, j, ans;
	long ip[1000];
	scanf("%d", &n);
	for (i = 0;i < n;i++)
	{
		scanf("%ld", &ip[i]);
	}
	ans = n + 1;
	for (i = 0;i < n - 1;i++)
	{
		for (j = i + 1;j < n;j++)
		{
			if (ip[i] == ip[j] && j - i < ans)
				ans = j - i;
		}
	}
	printf("%d\n", (ans <= n) ? ans : -1);
	return 0;
}

