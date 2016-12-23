// Puzzle I.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	long M, N;
	scanf("%ld%ld", &M, &N);
	(M*N == 0)? printf("0"): printf("%ld", M / 2 + N / 2 + 1);
	return 0;
}

