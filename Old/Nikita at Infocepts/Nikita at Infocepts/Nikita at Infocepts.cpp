// Nikita at Infocepts.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/holi-code/challenges/nikita-at-infocepts

#include <stdio.h>


long long nCr(int n, int r)
{
	long long ans = 1;
	int i;
	r = (r > n / 2) ? n - r : r;
	for (i = 1;i <= r;i++)
	{
		ans = ans*(n + 1 - i) / i;
	}
	return ans;
}



int main()
{
	int T, i;
	unsigned long long N = 0, arr[34];
	for (i = 0;N <=1000000000 ;i++)
	{
		arr[i] = N = nCr(i, i / 2);	
	}
	scanf("%d", &T);
	while (T--)
	{
		scanf("%llu", &N);
		i = 0;
		while (arr[i] < N)
		{
			i++;
		}
		printf("%d\n", i);
	}
	return 0;
}

