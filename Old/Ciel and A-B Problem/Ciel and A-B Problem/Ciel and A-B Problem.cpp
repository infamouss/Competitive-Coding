// Ciel and A-B Problem.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int A, B;
	scanf("%d%d", &A, &B);
	A -= B;
	printf("%d\n", A % 10 == 9 ? --A : ++A);
    return 0;
}

