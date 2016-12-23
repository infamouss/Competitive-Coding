// One more weird game.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/LTIME37/problems/OMWG

#include <stdio.h>

int main()
{
	int T, N, M;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &M, &N);
		printf("%ld\n", (M - 1)*N + (N - 1)*M);
	}
	return 0;
}

