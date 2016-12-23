// Chef and Remissness.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	long A, B;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld%ld", &A, &B);
		printf("%ld %ld\n", (A > B) ? A : B, A + B);
	}
    return 0;
}

