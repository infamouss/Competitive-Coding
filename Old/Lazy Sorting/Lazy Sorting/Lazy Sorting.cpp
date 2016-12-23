// Lazy Sorting.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/w21/challenges/lazy-sorting

#include <stdio.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iostream>




double fact(int n)
{
	double ans = 1;
	while (n > 0)
	{
		ans *= n;
		n--;
	}
	return ans;
}


using namespace std;

int main()
{
	int N, arr[101] = { 0 }, i, tmp;
	double ans;
	scanf("%d", &N);
	int prev = 0, sorted = 1;
	for (i = 0;i < N;i++)
	{
		scanf("%d", &tmp);
		if (prev > tmp)
		{
			sorted = -1;
		}
		prev = tmp;
		arr[tmp]++;
	}
	ans = fact(N);
	for (i = 0;i <= 100;i++)
	{
		if (arr[i] > 1)
		{
			ans /= fact(arr[i]);
		}
	}
	if (ans == 1 || sorted == 0)
	{
		printf("%lf", 0.000000);
	}
	else
	{
		printf("%lf", ans);
	}
	return 0;
}

