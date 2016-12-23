// Lazy Jem.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/COOK74/problems/TALAZY

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
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int T;
	long long N, B, M, ans;
	cin >> T;
	while (T--)
	{
		cin >> N >> B >> M;
		ans = 0;
		while (N>0)
		{
			ans += (N + 1) / 2 * M + B;
			N /= 2;
			M *= 2;
		}

		ans -= B;
		cout << ans << "\n";



	}




	return 0;
}
