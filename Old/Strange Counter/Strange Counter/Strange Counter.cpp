// Strange Counter.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/hourrank-11/challenges/strange-code

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long t, prevVal = 3;
	scanf("%lld", &t);
	t--;
	while (t >= prevVal)
	{
		t -= prevVal;
		prevVal *= 2;
	}
	printf("%ld", prevVal - t);
	return 0;
}

