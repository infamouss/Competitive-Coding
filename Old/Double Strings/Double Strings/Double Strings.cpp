// Double Strings.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	long N;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld", &N);
		printf("%ld\n", (N % 2) ? N - 1 : N);
	}
    return 0;
}

