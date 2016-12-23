// Maximum Perimeter Triangle.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/maximum-perimeter-triangle

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

	int N, i, j, k;
	cin >> N;
	vector<long long> arr(N);
	pair<long long, pair<long long, long long>> ans = make_pair(0, make_pair(0, 0));
	for (i = 0;i < N;i++)
		cin >> arr[i];
	sort(arr.rbegin(), arr.rend());
	int flag = 0;
	for (i = 0;i < N - 2 && flag == 0;i++)
		for (j = i + 1;j < N - 1 && flag == 0;j++)
			for (k = j + 1;k < N&&flag == 0;k++)
			{
				if (arr[i] < arr[j] + arr[k])
				{
					ans = make_pair(arr[i], make_pair(arr[k], arr[j]));
					flag = 1;
				}
			}


	if (ans.first == 0)
		cout << "-1\n";
	else
		cout << ans.second.first << " " << ans.second.second << " " << ans.first << "\n";



	return 0;
}