// Hackerland Radio Transmitters.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/university-codesprint/challenges/hackerland-radio-transmitters

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

	long long N, K, i, ans = 0;
	cin >> N >> K;
	vector<long> arr(N);
	for (i = 0;i < N;i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	i = 0;
	vector<long>::iterator val;
	while (i < N)
	{
		int prev = i;
		while (i < N&&arr[i] <= arr[prev] + K)
			i++;
		i--;
		ans++;
		prev = i;
		while (i < N&&arr[i] <= arr[prev] + K)
		{
			i++;
		}
	}
	cout << ans << "\n";

	return 0;
}
