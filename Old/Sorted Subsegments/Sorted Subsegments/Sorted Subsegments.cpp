// Sorted Subsegments.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/101hack38/challenges/sorted-subsegments

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>


using namespace std;

int main()
{
	long n, q, i, k, a, b;

	scanf("%ld%ld%ld", &n, &q, &k);
	vector<long long> v(n);
	for (i = 0;i < n;i++)
		scanf("%lld", &v[i]);
	while (q--)
	{
		scanf("%ld%ld", &a, &b);
		sort(v.begin() + a, v.begin() + b + 1);
	}
	printf("%lld", v[k]);




	return 0;
}

