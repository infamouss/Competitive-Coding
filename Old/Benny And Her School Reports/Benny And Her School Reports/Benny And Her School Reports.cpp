// Benny And Her School Reports.cpp : Defines the entry point for the console application.
// url : https://www.hackerearth.com/june-easy-16/algorithm/benny-and-her-school-reports/

#include <stdio.h>


int main()
{
	long long T, N, M, X, A, ans, tot;
	scanf("%lld", &T);
	while (T--)
	{
		scanf("%lld%lld%lld", &N, &M, &X);
		tot = (N + 1)*X;
		while (N--)
		{
			scanf("%lld", &A);
			tot -= A;
		}
		if (tot < 1)
		{
			printf("1");
		}
		else if(tot>M)
		{
			printf("Impossible");
		}
		else
		{
			printf("%lld", tot);
		}
		printf("\n");
	}
	return 0;
}

