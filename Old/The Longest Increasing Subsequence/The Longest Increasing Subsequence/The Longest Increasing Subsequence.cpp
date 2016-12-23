// The Longest Increasing Subsequence.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/longest-increasing-subsequent

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

	long N, i;
	cin >> N;
	vector<long> arr(N), pos;
	cin >> arr[0];
	pos.push_back(arr[0]);
	for (i = 1;i < N;i++)
		cin >> arr[i];
	for (i = 1;i < N;i++)
	{
		if (lower_bound(pos.begin(), pos.end(), arr[i]) != pos.end())
			*lower_bound(pos.begin(), pos.end(), arr[i]) = arr[i];
		else
			pos.push_back(arr[i]);
	}

	cout << pos.size() << "\n";

	return 0;
}
