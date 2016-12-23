#include "stdafx.h"
#include<stdio.h>
int root(int n);
int main()
{
	int n, ans;
	scanf_s("%d", &n);
	ans = root(n);
	printf("%d", ans);
	return 0;
}
int root(int n)
{
	int ans = 0;
	if (n <= 9)
	{
		ans = n;
	}
	else
	{
		ans = ans + root(n / 10) + n % 10;
	}
	if (ans / 10 >= 1)
	{
		n = ans;
		ans = root(n);
	}
	return (ans);
}