// SUPW.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/ZCOPRAC/problems/ZCO14002

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
	long N, i;
	scanf("%ld", &N);
	vector<long> ip(N + 4, 0);
	for (i = 1;i <= N;i++)
		scanf("%ld", &ip[i]);
	for (i = N;i >= 0;i--)
		ip[i] += min(ip[i + 1], min(ip[i + 2], ip[i + 3]));
	printf("%ld\n", ip[0]);
	return 0;
}

