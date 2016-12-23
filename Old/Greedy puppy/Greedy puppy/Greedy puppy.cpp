// Greedy puppy.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	long N, K;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld%ld", &N, &K);
		printf("%ld\n", N % (N / (N / K + 1) + 1));
	}
    return 0;
}

