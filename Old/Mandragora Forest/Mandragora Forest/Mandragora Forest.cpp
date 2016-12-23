// Mandragora Forest.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/mandragora

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

	long T;
	cin >> T;
	while (T--)
	{
		long N, i;
		cin >> N;
		vector<long> H(N);
		for (i = 0;i < N;i++)
			cin >> H[i];
		long long S = 1, P = 0, sub = 0;

		sort(H.begin(), H.end());
		H.push_back(0);
		for (i = N - 1;i >= 0;i--)
			H[i] += H[i + 1];
		

		for (i = 0;i < N;i++)
		{

			if ((S + 1)*H[i + 1] >= S*H[i])
			{
				S++;
				sub += H[i];
			}
			else
			{
				P += (H[i] - H[i + 1]) * S;
			}
		}
		cout << P << "\n";
	}
	return 0;
}