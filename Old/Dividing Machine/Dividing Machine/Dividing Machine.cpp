// Dividing Machine.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/SEPT16/problems/DIVMAC

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;



void sieve(vector<long>& primes,long N)
{
	long i, j;
	vector<bool> isPrime(N + 1, true);
	for (i = 2;i < N;i++)
	{
		if (isPrime[i] == true)
		{
			j = i;
			while (j <= N)
			{
				isPrime[j] = false;
				j += i;
			}
		}
	}


	for (i = 2;i < N;i++)
	{
		if (isPrime[i] == true)
			primes.push_back(i);
	}



}

long factorize(long N, vector<long>& primes, vector<long>& factors)
{
	//factors.push_back(0);
	factors.push_back(1);
	long i, j, k;

	for (i = 0;i < primes.size() && primes[i] <= N;i++)
	{

		while (N%primes[i] == 0)
		{
			factors.push_back(primes[i]);
			N /= primes[i];
		}

	}

	//factors[0] = factors.size() - 1;
	//reverse(factors.begin() + 2, factors.end());
	return factors.size();
}










const int N = 1e5;  // limit for array size
//int n;  // array size
//int t[2 * N];

void build(vector<vector<long>>& factors, vector<long>& segTree, long n) // build the tree
{
	for (long i = n - 1; i > 0; --i)
	{
		//segTree[i] = segTree[i << 1] + segTree[i << 1 | 1];
		if (factors[segTree[i << 1]][factors[segTree[i << 1]].size() - 1] < factors[segTree[i << 1 | 1]][factors[segTree[i << 1 | 1]].size() - 1])
		{
			segTree[i] = segTree[i << 1];
		}
		else
		{
			segTree[i] = segTree[i << 1 | 1];
		}
	}
}

void modify(int p, int value) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}

int query(vector<vector<long>>& factors, vector<long>& t, long n, int l, int r) {  // sum on interval [l, r)
	int res = 1;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[l++];
		res = min(res, res);
		if (r & 1) res += t[--r];
	}
	return res;
}










int main()
{
	int T, type;
	long L, R, N, M, i;
	vector<long> primes;
	sieve(primes, 1000000);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld%ld", &N, &M);
		vector<long> arr(N);
		vector<vector<long>> factors(N);
		vector<long> segTree(2 * N);
		for (i = 0;i < N;i++)
		{
			scanf("%ld", &arr[i]);
			//segTree[N + i] = factors[i][factorize(arr[i], primes, factors[i]) - 1];
			segTree[N + i] = i;
		}
			
		


		for (i = 0;i < N;i++)
		{

		}


		build(segTree, N);
		

		while (M--)
		{
			scanf("%d%ld%ld", &type, &L, &R);
			L--;R--;

			if (type == 0)//update
			{

			}
			else//return something
			{

			}











		}










		printf("\n");







	}






	return 0;
}

