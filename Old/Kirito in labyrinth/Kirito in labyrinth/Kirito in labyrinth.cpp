// Kirito in labyrinth.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/DEC16/problems/KIRLAB

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <unordered_map>

using namespace std;


void sieve(vector<int>& primes, int N)
{
	int i, j;
	vector<bool> isPrime(N + 1, true);
	isPrime[0] = isPrime[1] = false;

	for (i = 2;i <= N;i++)
	{
		if (isPrime[i] == true)
		{
			j = 2 * i;
			while (j <= N)
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
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	/*long T, lp;
	long long ans;
	cin >> T;
	for (lp = 1;lp <= T;lp++)
	{
	cout << "Case #" << lp << ": " << ans << "\n";
	}*/

	vector<int> primes;
	sieve(primes, 10000000);
	int T;
	cin >> T;
	while (T--)
	{
		int N, i, n1 = 0, maxxx = 0;
		cin >> N;
		vector<int> arr(N);
		for (i = 0;i < N;i++)
		{
			cin >> arr[i];
			maxxx = max(maxxx, arr[i]);
			if (arr[i] == 1)
				n1++;
		}
		if (n1 == N)
			cout << "1\n";
		else
		{
			vector<int> ans(maxxx + 1, 0);
			unordered_map<int, int> ans1;
			int maxx = 0;
			for (i = 0;i < N;i++)
			{
				int a = arr[i], j;
				vector<int> tmp;
				for (j = 0;primes[j] * primes[j] <= a;j++)
				{
					if (a%primes[j] == 0)
					{
						tmp.push_back(primes[j]);
						a /= primes[j];
						while (a%primes[j] == 0)
						{
							a /= primes[j];
						}
					}
				}
				if (a>=2)
				{
					tmp.push_back(a);
				}
				
				int len = tmp.size();
				for (j = maxx = 0;j < len;j++)
				{
					if (ans1.find(tmp[j]) == ans1.end())
					{
						ans1[tmp[j]] = 0;
					}
					maxx = max(ans1[tmp[j]], maxx);
				}
				maxx++;
				for (j = 0;j<len;j++)
				{
					ans1[tmp[j]] = maxx;
				}
			}
			maxx = 0;
			for (unordered_map<int, int>::const_iterator got = ans1.begin();got != ans1.end();got++)
			{
				maxx = max(maxx, got->second);
			}
			cout << maxx << "\n";
		}
	}
	return 0;
}
