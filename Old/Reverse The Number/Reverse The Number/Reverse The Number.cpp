// Reverse The Number.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	long N, ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld", &N);
		ans = 0;
		while (N)
		{
			ans = 10 * ans + N % 10;
			N = N / 10;
		}
		printf("%ld\n", ans);
	}
    return 0;
}

