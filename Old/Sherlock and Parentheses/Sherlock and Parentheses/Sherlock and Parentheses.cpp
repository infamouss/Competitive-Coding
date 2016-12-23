// Sherlock and Parentheses.cpp : Defines the entry point for the console application.
//

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

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);



	long T, lp, L, R;
	cin >> T;
	for (lp = 1;lp <= T;lp++)
	{
		cin >> L >> R;

		long long ans = min(L, R);
		ans = (ans + 1)*ans / 2;
		cout << "Case #" << lp << ": " << ans << "\n";

	}



	return 0;
}

