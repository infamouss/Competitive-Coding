// Combination Lock.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/world-codesprint-6/challenges/combination-lock

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
	vector<int> a(5), b(5);
	int i, ans = 0;
	for (i = 0;i < 5;i++)
		scanf("%d", &a[i]);
	for (i = 0;i < 5;i++)
		scanf("%d", &b[i]);
	for (i = 0;i < 5;i++)
	{
		ans += min(abs(a[i] - b[i]), 10 - abs(a[i] - b[i]));
	}
	printf("%d\n", ans);
	return 0;
}

