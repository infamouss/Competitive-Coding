// Matched Brackets.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/ZCOPRAC/problems/ZCO12001

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	long N;
	long i, lastMax, maxCount, pos = -1, maxSeq, maxPos, tmp;
	scanf("%ld", &N);
	vector<long> check(N + 1);
	stack<long> stk;
	i = maxCount = 0;
	lastMax = 0;
	check[0] = 0;
	for (i = 1;i <= N;i++)
	{
		scanf("%ld", &tmp);
		if (tmp == 1)
		{
			stk.push(i);
			check[i] = 0;
			maxCount++;
			if (maxCount > lastMax)
			{
				lastMax = maxCount;
				pos = i;
			}
		}
		else if (tmp == 2)
		{
			check[i] = stk.top();
			stk.pop();
			maxCount--;
		}
	}
	maxSeq = 0;
	for (i = 1;i <= N;i++)
	{
		if (check[i] && i - check[i] > maxSeq)
		{
			maxPos = check[i];
			maxSeq = i - check[i];
		}
	}
	printf("%ld %ld %ld %ld\n", lastMax, pos, maxSeq + 1, maxPos);
	return 0;
}

