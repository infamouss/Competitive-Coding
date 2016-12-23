#include "stdafx.h"
#include<stdio.h>
int lsb(int n, int acc);
int msb(int n);
int main()
{
	int n;
	scanf_s("%d", &n);
	printf("%d\n%d", lsb(n, 0), msb(n));
	return 0;
}
int lsb(int n, int acc)
{
	int ans;
	if (n == 0)
	{
		acc = acc;

	}
	else
	{
		acc = 10 * acc + n % 2;
		ans = lsb(n / 2, acc);
		acc = ans;
	}
	return (acc);
}
int msb(int n)
{
	int ans = 0;
	if (n == 0)
	{
		ans = 0;
	}
	else
	{
		ans = (n % 2) + 10 * msb(n / 2);
	}
	return (ans);
}