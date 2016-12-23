// Task for Alexey.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/NOV16/problems/ALEXTASK

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


using namespace std;

#define INFI LLONG_MAX


long long gcd(long long a, long long b)
{
	if (a%b == 0)
		return b;
	return gcd(b, a%b);
}


long long lcm(long long a, long long b)
{
	return a*b / gcd(a, b);
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
		int N, i, j;
		long long ans = INFI;
		cin >> N;
		vector<long long> arr(N);
		for (i = 0;i < N;i++)
			cin >> arr[i];
		for (i = 0;i < N - 1;i++)
			for (j = i + 1;j < N;j++)
				ans = min(ans, lcm(arr[i], arr[j]));

		cout << ans << "\n";

	}
	return 0;
}
