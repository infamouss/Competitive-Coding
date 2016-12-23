// Bon Appétit.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/world-codesprint-6/challenges/bon-appetit

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
	long N, K, bActual, bCharged, tmp, i, total = 0;
	scanf("%ld%ld", &N, &K);
	for (i = 0;i < N;i++)
	{
		scanf("%ld", &tmp);
		if (i != K)
			total += tmp;
		
	}
	bActual = total / 2;
	scanf("%ld", &bCharged);
	if (bActual == bCharged)
	{
		printf("Bon Appetit\n");
	}
	else
	{
		printf("%ld\n", bCharged - bActual);
	}
	return 0;
}

