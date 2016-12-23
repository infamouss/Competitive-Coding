// Count Permutations.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/NOV16/problems/CPERM

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

using namespace std;

#define MOD 1000000007

long long power(long long N)
{
	if (N <= 0)
		return 0;
	long long ans = 1, mul = 2;
	while (N!=0)
	{
		if (N % 2 == 1)
		{
			ans = (ans*mul) % MOD;
		}
		mul = (mul*mul) % MOD;
		N /= 2;
	}
	return (ans - 2) % MOD;
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



	int T;
	cin >> T;
	while (T--)
	{
		long long N, ans;
		cin >> N;
		cout << power(N - 1) << "\n";
	}
	return 0;
}

