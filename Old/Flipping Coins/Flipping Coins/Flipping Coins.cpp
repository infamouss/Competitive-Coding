// Flipping Coins.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int head[100000] = { 0 }, Oi, A, B;
	long n, q, i, j, ans;
	scanf("%ld%ld", &n, &q);
	for (i = 0;i < q;i++)
	{
		scanf("%d %d %d", &Oi, &A, &B);
		if (Oi == 0)
		{
			for (j = A;j <= B;j++)
			{
				if (head[j] == 0)
				{
					head[j] = 1;
					ans++;
				}
				else
				{
					head[j] = 0;
					ans--;
				}
			}
		}
		else
		{
			ans = 0;
			for (j = A;j <= B;j++)
			{
				if (head[j] == 1)
				{
					ans++;
				}
			}
			printf("%ld\n", ans);
		}
	}
	return 0;
}

