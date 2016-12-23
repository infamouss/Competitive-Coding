// Marbles.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	long N, i;
	long long ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld", &N);
		if (N == 1)
		{
			printf("%d\n", 1);
		}
		else if (N == 2)
		{
			printf("%d\n", 2);
		}
		else
		{

			ans = 2;
			for (i = 1;i < N - 1;i++)
			{
				ans += 2 * i*(N - i - 1);
				ans %= (1000000007);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}

