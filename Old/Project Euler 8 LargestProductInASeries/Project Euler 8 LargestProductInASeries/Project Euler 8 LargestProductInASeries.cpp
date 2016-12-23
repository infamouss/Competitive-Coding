// Project Euler 8 LargestProductInASeries.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, K, N, i, j;
	char ip[1001];
	long ans, tmp;



	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%s", &N, &K, ip);
		ans = 1;
		for (i = 0;i < K;i++)
		{
			ans = ans*(ip[i] - '0');
		}
		tmp = ans;
		while (i < N)
		{
			if (ip[i - K] == '0')
			{
				ans = 1;
				for (j = i - K + 1;j <= i;j++)
				{
					ans = ans*(ip[j] - '0');
				}
				tmp = ans;
			}
			else
			{
				tmp = tmp*(ip[i] - '0') / (ip[i - K] - '0');
			}
			if (ans < tmp)
			{
				ans = tmp;
			}
			i++;
		}

		printf("%ld\n", ans);
	}




	return 0;
}

