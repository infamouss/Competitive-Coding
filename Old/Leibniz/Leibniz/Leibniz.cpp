// Leibniz.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	long double n, a, i;
	scanf("%d", &t);
	while (t--)
	{
		a = 1;
		scanf("%f", &n);
		for (i = 1;i < n;i++)
		{
			a += pow(-1, i) / (2 * i + 1);
		}
		printf("%.15f\n", a);
	}
	return 0;
}

