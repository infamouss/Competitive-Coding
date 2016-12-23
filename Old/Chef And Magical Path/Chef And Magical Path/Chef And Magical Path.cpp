// Chef And Magical Path.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/APRIL16/problems/CHEFPATH

#include <stdio.h>


int main()
{
	long T;
	long long M, N;
	scanf("%ld", &T);
	while (T--)
	{
		scanf("%lld%lld", &N, &M);
		if ((N == 1 && M > 2) || (M == 1 && N > 2))
			printf("No\n");
		else if ((N % 2 == 0) || (M % 2 == 0))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

