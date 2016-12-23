// Andrash and Stipendium.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/JULY16/problems/EGRANDR

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	long N;
	scanf("%d", &T);
	while (T--)
	{
		int tmp, num2 = 0, num5 = 0;
		long total;
		scanf("%ld", &N);
		total = N * 4;
		while (N--)
		{
			scanf("%d", &tmp);
			total -= tmp;
			if (tmp == 2)
				num2++;
			if (tmp == 5)
				num5++;
		}
		if (num2 != 0 || num5 == 0 || total > 0)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
	return 0;
}

