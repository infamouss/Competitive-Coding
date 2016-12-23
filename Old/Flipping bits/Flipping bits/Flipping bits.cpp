// Flipping bits.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	unsigned long n;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lu", &n);
		printf("%lu\n", ~n);
	}
	return 0;
}

