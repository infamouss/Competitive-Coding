// Currency Arbitrage.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/blackrock-codesprint/challenges/currency-arbitrage

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <set>
#include <functional>
#include <algorithm>


using namespace std;

int main()
{
	int N;
	double UE, EG, GU;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%lf%lf%lf", &UE, &EG, &GU);
		double din = UE*EG*GU;
		double ans = 100000.0 / din;
		ans -= 100000;
		printf("%lld\n", (ans > 0.0) ? (long long)ans : 0);
	}



	return 0;
}

