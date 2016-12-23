#include "stdafx.h"
#include<stdio.h>

int main()
{
	int t, n, i, j, k, a[100][100] = {0};
	scanf_s("%d",&t);
	for (i = 0; i < t; i++)
	{
		scanf_s("%d",&n);
		for (j = 0; j < n; j++)
			for (k = 0; k <= j; k++)
				scanf_s("%d", &a[j][k]);
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