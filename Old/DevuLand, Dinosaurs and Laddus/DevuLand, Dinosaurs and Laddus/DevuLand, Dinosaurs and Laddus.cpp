#include "stdafx.h"
#include<stdio.h>
#include<math.h>
int main()
{
	int t, n, tmp, i, j, ans[100000] = {0}, count;
	scanf_s("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf_s("%d", &n);
		count = 0;
		for (j = 0; j < n; j++)
		{
			scanf_s("%d", &tmp);
			ans[i] = ans[i] + abs(count);
			count = count + tmp;
			
		}
	}
	for (i = 0; i < t; i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}