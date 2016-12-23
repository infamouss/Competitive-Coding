// Red John is Back.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/red-john-is-back

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

using namespace std;
vector<long long> a(136386176);
vector<bool> isPrime(136386176, true);

void sieve(long N)
{
	long i, j;
	
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
	a[0] = 0;
	for (i = 1;i <= N;i++)
	{
		a[i] = a[i - 1] + 1 * isPrime[i];
	}
	
}

long long power(int a, int b)
{
	long long ans = 1, mul = a;
	while (b > 0)
	{
		if (b % 2 != 0)
			ans *= mul;
		mul *= mul;
		b /= 2;
	}
	return ans;
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

	int T, N, i, j;
	long long ans;
	sieve(136386175);
	cin >> T;
	while (T--)
	{
		cin >> N;
		
		if (N <= 3)
			cout << "0\n";
		else
		{
			ans = 1;
			for (i = 4;i <= N;i += 4)
			{
				ans += power(N - i + 1, i / 4);
			}
			cout << a[ans] << "\n";
		}
	}
	return 0;
}
