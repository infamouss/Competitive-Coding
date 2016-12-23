// Polynomial and its roots.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int N, i;
	long coeff[21];
	scanf("%d", &N);

	for (i = 0;i <= N;i++)
	{
		scanf("%ld", &coeff[i]);
	}
	printf("%ld %ld", -1 * coeff[N - 1] / coeff[N], ((N % 2 == 0) ? 1 : -1)* coeff[0] / coeff[N]);


	return 0;
}

