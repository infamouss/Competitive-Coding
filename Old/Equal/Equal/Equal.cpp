// Equal.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/equal

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
		long N, i;
		cin >> N;
		vector<long> arr(N);
		for (i = 0;i < N;i++)
			cin >> arr[i];
		int M = *min_element(arr.begin(), arr.end());
		int r = 1e9;
		for (int t = M - 4; t <= M; t++) {
			int s = 0;
			for (int i = 0; i < N; i++) {
				int D = arr[i] - t;
				s += D / 5, D %= 5;
				s += D / 2, D %= 2;
				s += D;
			}
			r = min(r, s);
		}
		cout << r << "\n";
	}
	return 0;
}

