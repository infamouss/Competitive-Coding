// Aria's Loops.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/101hack41/challenges/arias-loops

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


#define lim 1000000007
long long fact[100000001] = { 1 };

void foo()
{
	long i = 1;
	for (;i <= 100000000;i++)
	{
		fact[i] = (fact[i - 1] * i) % lim;
	}
}












long long power(long N, long n)
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
	foo();
	unsigned long long ans = 1, div;
	div = (fact[r] * fact[n - r]) % lim;
	ans = (fact[n] * power(div, lim - 2)) % lim;
	return ans;
}




//unsigned long long solve()



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

	unsigned long long N, K;
	cin >> N >> K;
	cout << nCr(N, K);




	return 0;
}
