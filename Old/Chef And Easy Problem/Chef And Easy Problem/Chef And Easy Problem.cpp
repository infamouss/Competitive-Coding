#include "stdafx.h"
#include<stdio.h>

int main()
{
	int a[100000], t, n, i, j, k, tmp, sum[10];
	scanf_s("%d", &t);
	for (k = 0; k < t; k++)
	{
		scanf_s("%d",&n);
		sum[k] = 0;
		for (i = 0; i < n; i++)
		{
			scanf_s("%d", &a[i]);
		}
		for (i = 0; i < n - 1; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (a[i] < a[j])
				{
					tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
				}
			}
		}
		for (i = 0; i < n; i += 2)
		{
			sum[k] = sum[k]+ a[i];
		}
	}
	for (k = 0; k < t; k++)
	{
		printf("%d\n",sum[k]);

	}
	
	return 0;
}