// Clique.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/clique

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	long T;
	double N, M;
	scanf("%ld", &T);
	while (T--)
	{
		scanf("%lf%lf", &N, &M);
		//float ans = (1.0 + floor(sqrt(1.0 + 8.0 * M))) / 2.0;
		double ans = N*N / (N*N - 2 * M);
		printf("%0.lf\n", ceil(ans));



	}








	return 0;
}

