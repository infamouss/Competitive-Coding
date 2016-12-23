// Watson asks Does Permutation Exist.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/COOK75/problems/PERMEXIS

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
	long N, i;
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<long long> arr(N);
		for (i = 0;i < N;i++)
			cin >> arr[i];
		sort(arr.begin(), arr.end());

		int flag = 0;
		for (i = 0;i < N - 1 && flag == 0;i++)
		{
			if (arr[i + 1] - arr[i] > 1)
				flag = 1;
		}
		if (flag == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}