#include "stdafx.h"
#include<stdio.h>
int carry(int a[], int i);
int main()
{
	int ans[30], t, n, i,j,k=0;
	scanf_s("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf_s("%d", &n);
		ans[0] = 1;
		for (j = 1; j <= n; j++)
		{
			ans[0] = ans[0] * j;
		}
	}
	return 0;
}