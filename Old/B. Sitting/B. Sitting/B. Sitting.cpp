// B. Sitting.cpp : Defines the entry point for the console application.
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
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	long T, lp;
	long long ans, R, C;
	cin >> T;
	for (lp = 1;lp <= T;lp++)
	{
		cin >> R >> C;
		if (R == 1 && C == 1)
		{
			ans = 1;
		}
		else if (R == 1 || C == 1)
		{
			int a=1, b=1;
			if (R == 1)
			{
				b = C;
			}
			else
			{
				b = R;
			}
			ans = b / 3 * 2 + b % 3;
		}
		else if (R == 2 || C == 2)
		{
			int a = 1, b = 1;
			if (R == 2)
			{
				b = C;
			}
			else
			{
				b = R;
			}
			ans = (b / 3 * 2 + b % 3) * 2;
		}
		else if (R > 2 && C > 2)
		{

			// r/3 + r%3/1
			ans = (R / 3) * (C / 3 * 2 + C % 3);
			if (R % 3 >= 1)
				ans += (C / 3 * 2 + C % 3);
			// r/3 + r%3/2
			long long c = C - 1;
			ans += (R / 3)*(c / 3 * 2 + c % 3);
			if (R % 3 == 2)
				ans += (c / 3 * 2 + c % 3);
			c = C - 2;
			ans += (R / 3)*(c / 3 * 2 + c % 3 + 1);
			//if (R % 3 == 2)
			//	ans += (c / 3 * 2 + c % 3 + 1);
		}
		

	cout << "Case #" << lp << ": " << ans << "\n";
	}





	return 0;
}



