// Chefland and Electricity.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/JULY16/problems/CHEFELEC

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

long nextRight(char ip[], long current)
{
	current++;
	while (ip[current] != '\0'&&ip[current] != '1')
	{
		current++;
	}
	if (ip[current] == '\0')
	{
		current = -1;
	}
	return current;
}


int main()
{
	int T;
	long N, ip[100000], i, left, right, ans;
	char power[100001];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld", &N);
		scanf("%s", power);
		for (i = 0;i < N;i++)
		{
			scanf("%ld", &ip[i]);
		}
		left = 0;
		right = -1;
		ans = 0;
		while (power[left] == '0')
		{
			left++;
		}
		ans += ip[left] - ip[0];
		right = nextRight(power, left);
		while (right != -1)
		{
			long maxLength = 0;
			for (i = left + 1;i <= right;i++)
			{
				maxLength = max(maxLength, ip[i] - ip[i - 1]);
			}
			ans = ans + ip[right] - ip[left] - maxLength;
			left = right;
			right = nextRight(power, left);
		}
		ans += ip[N - 1] - ip[left];
		printf("%ld\n", ans);
	}
	return 0;
}

