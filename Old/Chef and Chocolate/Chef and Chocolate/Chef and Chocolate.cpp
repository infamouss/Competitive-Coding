// Chef and Chocolate.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/AUG16/problems/CHCHCL

#include <stdio.h>4
#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

int main()
{
	int T;
	unsigned long long m, n;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%llu%llu", &m, &n);
		if (m > 1 && n > 1)
			printf("%s\n", ((m*n) % 2 ? "No" : "Yes"));
		else
		{
			m = (n == 1) ? m : n;
			printf("%s\n", (m % 2 ? "No" : "Yes"));
		}	
	}
	return 0;
}

