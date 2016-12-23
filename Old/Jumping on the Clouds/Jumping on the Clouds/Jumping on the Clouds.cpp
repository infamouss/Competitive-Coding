// Jumping on the Clouds.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/world-codesprint-april/challenges/jumping-on-the-clouds

#include <stdio.h>


int main()
{
	int n, tmp, ans = -1, i, arr[101];
	scanf("%d", &n);
	arr[n] = 1;
	for (i = 0;i < n;i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0;i < n;i++)
	{
		if (arr[i + 2] == 0)
		{
			i++;
		}
		ans++;
	}
	printf("%d", ans);
	return 0;
}

