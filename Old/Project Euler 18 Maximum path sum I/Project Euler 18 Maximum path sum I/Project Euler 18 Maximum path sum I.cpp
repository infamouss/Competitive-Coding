// Project Euler 18 Maximum path sum I.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int t, n, j, k, a[100][100] = { 0 };
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for (j = 0; j < n; j++)
			for (k = 0; k <= j; k++)
			scanf("%d", &a[j][k]);
		for (j = n - 2; j >= 0; j--)
			for (k = 0; k <= j; k++)
			if (a[j + 1][k] < a[j + 1][k + 1])
			a[j][k] += a[j + 1][k + 1];
			else
				a[j][k] += a[j + 1][k];
		printf("%d\n", a[0][0]);
	}
	return 0;
}

