// Save The Trees.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/problems/KOL1509

#include <stdio.h>


int main()
{
	int T;
	long N, i, j;
	long long a[100000], ans, prevX, prevY;
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%ld", &N);
		for (i = 0;i < N;i++)
		{
			scanf("%lld", &a[i]);
		}
		prevX = a[0];
		prevY = a[1];


		for (i = 0;i < N - 1;i++)
		{
			for (j = i + 1;j < N;j++)
			{
				ans += prevX*a[j] - prevY*a[i];
				prevX = a[i];
				prevY = a[j];
			}
		}
		ans += prevX*a[1] - prevY*a[0];

		printf("%lld\n", (ans > 0) ? ans : -ans);


	}





	return 0;
}

