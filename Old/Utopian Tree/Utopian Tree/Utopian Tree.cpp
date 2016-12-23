#include "stdafx.h"
#include<stdio.h>
#include<math.h>

int main()
{
	int t, i, n, j;
	long long ans;
	scanf_s("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf_s("%d", &n);
		ans = 1;
		for (j = 0; j < n; j++)
		{
			if (j % 2 != 0)
			{
				ans = ans + 1;
			}
			else
			{
				ans = 2 * ans;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}