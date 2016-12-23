#include "stdafx.h"
#include<stdio.h>


int main()
{
	int t, n, ans, i, j, tmp, max;
	scanf_s("%d",&t);
	for (i = 0; i < t; i++)
	{
		max = 0;
		int a[100001] = { 0 };
		ans = 0;
		scanf_s("%d", &n);
		for (j = 0; j < n; j++)
		{
			scanf_s("%d", &tmp);
			a[tmp]++;
			if (tmp > max)
			{
				max = tmp;
			}
		}
		for (j = 0; j <= max; j++)
		{
			if (a[j]>ans)
				ans = a[j];
		}
		printf("%d\n", n - ans);
	}
	return 0;
}

