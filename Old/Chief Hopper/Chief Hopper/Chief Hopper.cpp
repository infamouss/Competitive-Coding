// Chief Hopper.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/chief-hopper

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


	long N, i, ans = 0;
	cin >> N;
	vector<long> arr(N);
	for (i = 0;i < N;i++)
		cin >> arr[i];
	for (i = N - 1;i >= 0;i--)
		ans = (ans + arr[i] + 1) / 2;
	cout << ans << "\n";
	return 0;
}

