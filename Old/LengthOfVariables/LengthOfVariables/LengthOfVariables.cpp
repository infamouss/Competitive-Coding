// LengthOfVariables.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>

int main()
{
	int i=1;
	float f=1;
	char c=1;
	long l=1;
	double d=1;
	long long ll=1;
	long double ld=1;
	/*while (i>0)
	{
		i = i * 2;
	}
	i--;
	printf("%d\n", i);
	while (f>0)
	{
		f = f * 2;
	}
	f--;
	while (c > 0)
	{
		c = c * 2;
	}
	c--;
	while (l>0)
	{
		l = l * 2;
	}
	l--;
	while (d>0)
	{
		d = d * 2;
	}
	d--;
	while (ll > 0)
	{
		ll = ll * 2;
	}
	ll--;
	while (ld > 0)
	{
		ld = ld*2;
	}
	ld--;
	printf("int:%d\nfloat:%f\nchar:%c\nlong:%ld\ndouble:%lf\nlong long:%lld\nlong double:%Lf", i, f, c, l, d, ll, ld);*/
	printf("int:%d\nfloat:%d\nchar:%d\nlong:%d\ndouble:%d\nlong long:%d\nlong double:%d", sizeof(int), sizeof(float),sizeof(char),sizeof(long),sizeof(double),sizeof(long long),sizeof(long double));
	return 0;
}

