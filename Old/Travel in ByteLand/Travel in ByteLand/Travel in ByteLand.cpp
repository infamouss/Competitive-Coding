// Travel in ByteLand.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


long long arr[2501][2501] = { 0 };


int main()
{
	int M, N, i, j, k, tmp;
	long long sum1, sum2, sum3;

	scanf("%d%d", &M, &N);

	for (i = 1;i <= N;i++)
	{
		for (j = 1;j <= M;j++)
		{
			if (i == 1 && j == 1)
			{
				scanf("%lld", &arr[i][j]);
			}
			else
			{
				scanf("%d", &tmp);
				if (tmp == 0)
				{
					arr[i][j] = 0;
				}
				else
				{
					sum1 = sum2 = sum3 = 0;
					for (k = 1;k<i;k++)
					{
						sum1 = sum1 + arr[k][j];
					}
					sum1 = sum1 % (1000000007);
					for (k = 1;k<j;k++)
					{
						sum2 = sum2 + arr[i][k];
					}
					sum2 = sum2 % (1000000007);
					for (k = 1;i - k>0 && j - k>0;k++)
					{
						sum3 = sum3 + arr[i - k][j - k];
					}
					sum3 = sum3 % (1000000007);

					sum1 = (sum1 + sum2 + sum3) % (1000000007);
					arr[i][j] = (tmp*sum1) % 1000000007;

				}
			}





		}
	}


	printf("%lld\n", arr[M][N]);




	return 0;
}

