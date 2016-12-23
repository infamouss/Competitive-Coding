// Reverse Game.cpp : Defines the entry point for the console application.
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
		printf("%ld\n", (K >= N / 2) ? (N - 1 - K) * 2 : 2 * K + 1);
	}
	return 0;
}

