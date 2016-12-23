// Sam and sub-strings.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/sam-and-substrings

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
#define mod 1000000007





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

	

	string N;
	
	
	cin >> N;
	reverse(N.begin(),N.end());
	long i = 1;
	long long prev, mul = 1, sum, ans;
	ans = prev = N[0] - '0';
	sum = ans;
	while (N[i]!='\0')
	{
		mul = (mul * 10 + 1) % mod;
		mul %= mod;
		ans = (N[i] - '0')*mul +  prev;
		ans %= mod;
		prev = ans;
		sum += ans;
		sum %= mod;
		i++;
	}
	cout << sum << "\n";
	return 0;
}

