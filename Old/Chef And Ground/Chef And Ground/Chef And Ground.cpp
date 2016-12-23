#include "stdafx.h"
#include<stdio.h>
int main()
{
	int t, n, m, i, j, sum, max, tmp;
	char a[100];
	scanf_s("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf_s("%d%d", &n, &m);
		scanf_s("%d", &max);
		sum = m + max;
		for(j = 1; j < n; j++)
		{
			scanf_s("%d", &tmp);
			sum = sum + tmp;
			if (max < tmp)
			{
				max = tmp;
			}
		}
		if (((sum%n) == 0) && ((sum/n) >= max))
		{
			a[i] = 0;
		}
		else
		{
			a[i] = 1;
		}
	}
	for (i = 0; i < t; i++)
	{
		if (a[i] == 0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}