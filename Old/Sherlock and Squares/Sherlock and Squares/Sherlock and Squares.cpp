// Sherlock and Squares.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	long a, b;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%ld%ld", &a, &b);
		if ((int)sqrt(a)*(int)sqrt(a) == a)
		{
			printf("%d\n", (int)sqrt(b) - (int)sqrt(a) + 1);
		}
		else
		{
			printf("%d\n", (int)sqrt(b) - (int)sqrt(a));
		}
	}






	return 0;
}

