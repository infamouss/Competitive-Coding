// Beautiful Triplets.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/world-codesprint-april/challenges/beautiful-triplets

#include <stdio.h>


int main()
{
	int n, d, i, arr[10001], ans = 0, start, mid, end;
	scanf("%d%d", &n, &d);
	for (i = 0;i < n;i++)
	{
		scanf("%d", &arr[i]);
	}
	start = 0;
	mid = 1;
	end = 2;
	while (end < n)
	{
		if (arr[mid] * 2 == arr[start] + arr[end] && arr[end] - arr[mid] == d)
		{
			ans++;
			end++;
			mid++;
			start++;
		}
		else if (arr[end] - arr[mid] < d)
		{
			end++;
		}
		else if (arr[mid] - arr[start] < d || arr[end] - arr[mid] > d)
		{
			mid++;
		}
		else if (arr[mid] - arr[start] > d)
		{
			start++;
		}
	}
	printf("%d", ans);
	return 0;
}

