// Chef and Array and K.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/JUNE16/problems/CHEFARK

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#define lim 1000000007
long long fact[100001] = { 1 };

void foo()
{
	long i = 1;
	for (;i <= 100000;i++)
	{
		fact[i] = (fact[i - 1] * i) % lim;
	}
}












long long power(long N,long n)
{
	unsigned long long ans = 1, multiple = N;
	while (n != 0)
	{
		if (n % 2 != 0)
		{
			ans = ans*multiple;
			ans = ans%lim;
		}


		multiple *= multiple;
		multiple %= lim;

		n = n / 2;
	}
	return ans;
}



unsigned long long nCr(long n, long r)
{
	unsigned long long ans = 1, div;
	div = (fact[r] * fact[n - r]) % lim;
	ans = (fact[n] * power(div, lim - 2)) % lim;
	return ans;
}


unsigned long long getAns(long N, long K, int n)
{
	unsigned long long ans = 0;

	while (K >= 0)
	{
		ans += nCr(N, K);
		ans = ans%lim;
		K -= n;
	}
	return ans;
}



int main()
{
	int T;
	long N, K, i, tmp, numZeros;
	unsigned long long ans;

	foo();
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld%ld", &N, &K);
		numZeros = 0;

		for (i = 0;i < N;i++)
		{
			scanf("%ld", &tmp);
			if (tmp == 0)
			{
				numZeros++;
			}
		}
		N = N - numZeros;

		if (numZeros != 0)
		{
			if (K >= N)
			{
				//ans=2^n
				K = N;
				ans = power(2,N);
			}
			else
			{
				ans = getAns(N, K, 1);
			}
		}
		else
		{
			if (K >= N)
			{
				ans = power(2, N - 1);
			}
			else
			{
				ans = getAns(N, K, 2);
			}
		}
		printf("%llu\n", ans);
	}
	return 0;
}

