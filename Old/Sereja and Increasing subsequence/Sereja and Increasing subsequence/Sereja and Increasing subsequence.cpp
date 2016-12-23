// Sereja and Increasing subsequence.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/DEC16/problems/SEAINCR

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


int LIS(vector<int>& arr, int L, int R)
{
	vector<long> pos;
	pos.push_back(arr[L]);
	for (vector<int>::const_iterator it = arr.begin() + L;it != arr.end() && it != arr.begin() + R;it++)
	{
		if (lower_bound(pos.begin(), pos.end(), *it) != pos.end())
			*lower_bound(pos.begin(), pos.end(), *it) = *it;
		else
			pos.push_back(*it);
	}
	return pos.size();
}


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
		int M, N, i, L, R;
		cin >> N >> M;
		vector<int> arr(N);
		for (i = 0;i < N;i++)
			cin >> arr[i];
		while (M--)
		{
			cin >> L >> R;
			L--;
			cout << LIS(arr, L, R) << "\n";
		}
	}
	return 0;
}

