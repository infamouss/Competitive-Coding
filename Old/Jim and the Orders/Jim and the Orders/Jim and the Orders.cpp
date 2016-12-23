// Jim and the Orders.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/jim-and-the-orders

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int> & b)
{
	if (a.second < b.second)
		return true;
	else if (a.second == b.second)
	{
		if (a.first < b.first)
			return true;
		else
			return false;
	}
	return false;
}

int main()
{
	int N, i;
	long start, end;
	scanf("%d", &N);
	vector<pair<int, int>> ip(N);
	for (i = 1;i <= N;i++)
	{
		scanf("%ld %ld", &start, &end);
		ip[i - 1].first = i;
		ip[i - 1].second = start + end;
	}
	stable_sort(ip.begin(), ip.end(), comp);

	for (i = 0;i < N;i++)
		printf("%ld ", ip[i].first);
	return 0;
}

