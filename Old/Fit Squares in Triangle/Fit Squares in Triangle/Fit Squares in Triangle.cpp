// Fit Squares in Triangle.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, B;
	long ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &B);
		B = (B - 2) / 2;
		printf("%ld\n", B*(B + 1) / 2);
	}
    return 0;
}

