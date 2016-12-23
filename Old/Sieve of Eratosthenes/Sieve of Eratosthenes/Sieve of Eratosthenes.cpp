// Sieve of Eratosthenes.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;


void sieve(vector<int>& primes,int N)
{
	int i, j;
	vector<bool> isPrime(N + 1, true);
	isPrime[0] = isPrime[1] = false;

	for (i = 2;i <= N;i++)
	{
		if (isPrime[i] == true)
		{
			j = 2 * i;
			while (j<=N)
			{
				isPrime[j] = false;
				j += i;
			}
		}
	}
	for (i = 0;i <= N;i++)
		if (isPrime[i])
			primes.push_back(i);
}







int main()
{
	vector<int> primes;
	sieve(primes,10000000);
	for (int i = 0;i < 100000;i++)
		cout << primes[i] << "\n";


	return 0;
}

