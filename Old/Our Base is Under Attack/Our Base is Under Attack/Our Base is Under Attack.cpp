// Our Base is Under Attack.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/DEC16/problems/BASE

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
	cout << "Case #" << lp << ": " << ans << "\N";
	}*/

	long long T;
	cin >> T;
	while (T--)
	{
		long long N;
		cin >> N;
		if (N == 0)
			cout << "0\n";
		else if (N == 1)
			cout << "INFINITY\n";
		else
		{
			//REFERENCE : https://oeis.org/A216411
			long long i, s = 0;
			for (i = 1;i < logl((long double)N) / logl((long double)2) + 1; i++)
				s += (floorl(powl(((long double)N + .5), ((long double)1 / (long double)i))) - floorl(pow((((long double)N + .2) / 2), ((long double)1 / (long double)i))));
			cout << s << "\n";
		}
	}
	return 0;
}


