// Sherlock and the Ugly Flower.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/COOK75/problems/UGLYF

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
	char a[100001], b[100001];
	long i, ans, l1, l2, j;
	while (T--)
	{
		scanf("%s%s", a, b);

		vector<long> s1[26], s2[26];
		i = 0;
		while (a[i] != '\0')
		{
			s1[a[i] - 'A'].push_back(i);
			i++;
		}
		l1 = i;
		i = 0;
		while (b[i] != '\0')
		{
			s2[b[i] - 'A'].push_back(i);
			i++;
		}
		l2 = i;


		ans = l1 + l2;
		bool flag = false;

		for (i = 0;i < 26;i++)
		{
			long d1 = -1, d2 = -1;
			for (j = 0;j < s1[i].size();j++)
			{
				if (abs(l1/2 - s1[i][j]) < abs(l1/2 - d1))
					d1 = s1[i][j];
			}


			for (j = 0;j < s2[i].size();j++)
			{
				if (abs(l2/2 - s2[i][j]) < abs(l2/2 - d2))
					d2 = s2[i][j];
			}

			long w1 = d1, w2 = d2, w3 = l1 - d1 - 1, w4 = l2 - d2 - 1;

			if (d1 != -1 && d2 != -1)
				flag = true;

			//if(abs(w1-w2)+abs(w2-w3)+abs(w3-w4)+abs(w4-w1)<ans)
			ans = min(ans, abs(w1 - w2) + abs(w2 - w3) + abs(w3 - w4) + abs(w4 - w1));




		}
		if (!flag)
			ans += abs(l1 - l2);
		cout << ans << "\n";


	}


	return 0;
}

