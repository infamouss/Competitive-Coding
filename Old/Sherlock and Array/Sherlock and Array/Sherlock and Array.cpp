// Sherlock and Array.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, A[100000], flag;
	long N, i;
	long long Lsum, Rsum;
	scanf("%d", &T);
	while (T--)
	{
		Lsum = Rsum = 0;
		flag = 0;
		scanf("%ld", &N);
		for (i = 0;i < N;i++)
		{
			scanf("%d", &A[i]);
			Lsum += A[i];
		}
		if (N == 1)
		{
			printf("YES\n");
		}
		else if (N == 2)
		{
			printf("NO\n");
		}
		else
		{
			i = 2;
			Lsum = Lsum - (A[N - 1] + A[N - 2]);
			Rsum = A[N - 1];
			if (Lsum == Rsum)
			{
				flag = 1;
			}
			while (i < N&&flag == 0)
			{
				Lsum -= A[N - 1 - i];
				Rsum += A[N - i];
				if (Lsum == Rsum)
				{
					flag = 1;
				}
				i++;
			}
			printf("%s\n", (flag == 0) ? "NO" : "YES");
		}
	}
	return 0;
}

