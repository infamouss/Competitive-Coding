// IRON MAN AND NATURAL NUMBER.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/CDRO2016/problems/MARVEL1

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
		long L, O, i, j, ans = 0;
		cin >> L >> O;
		for (i = 1;i < L;i++)
		{
			for (j = i + 1;j <= L;j++)
			{
				if ((i + j) % O == 0)
					ans++;
			}
		}
		cout << L << "\n";

	}



	return 0;
}
