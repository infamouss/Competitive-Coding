// Chillar and Gifts.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

int numBits(unsigned long long n)
{
	int ans = 0;
	while (n != 0)
	{
		ans += (n % 2) ? 1 : 0;
		n = n / 2;
	}
	return ans;
}

int main()
{
	int T;
	long long ans, i, j, N, arr[100000], tmp;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%llu", &N);
		for (i = 0;i < N;i++)
		{
			scanf("%llu", &arr[i]);
		}
		ans = 0;

		for (i = 0;i < N - 1;i++)
		{
			for (j = i + 1;j < N;j++)
			{
				tmp = arr[i] ^ arr[j];

				ans += numBits(tmp);

			}
		}
		printf("%llu\n", ans);


	}





	return 0;
}

