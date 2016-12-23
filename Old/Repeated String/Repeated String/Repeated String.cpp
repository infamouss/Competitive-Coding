// Repeated String.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/hourrank-12/challenges/repeated-string

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

int main()
{
	string S;
	long long n, ans;
	long long i = 0, count = 0;
	cin >> S;
	scanf("%lld", &n);
	while (S[i]!='\0')
	{
		if (S[i] == 'a')
			count++;
		i++;
	}
	ans = (n / i)*count;
	n = n%i;
	i = 0;
	while (i < n)
	{
		if (S[i] == 'a')
			ans++;
		i++;
	}
	printf("%lld\n", ans);
	return 0;
}

