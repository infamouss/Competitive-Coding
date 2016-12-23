// Nikita and the Game.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/array-splitting

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


int solve(vector<long>& arr, long start, long end, long long sm)
{
	if (start == end)
		return 0;
	if (sm == 0)
		return end - start;
	long i;
	long long sum = 0;
	for (i = start;i<=end && 2 * sum < sm;i++)
		sum += arr[i];
	if (2 * sum == sm)
		return 1 + max(solve(arr, start, i - 1, sum), solve(arr, i, end, sum));
	return 0;
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
	long N, i;
	long long sum;
	cin >> T;
	while (T--)
	{
		cin >> N;
		sum = 0;
		vector<long> arr(N);
		for (i = 0;i < N;i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}
		int ans = solve(arr, 0, N - 1, sum);
		cout << ans << "\n";
	}
	return 0;
}

