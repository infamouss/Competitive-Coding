// Tailor Shop.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/w27/challenges/tailor-shop

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


	long long n, p, i, ans = 0, prev = 0;
	cin >> n >> p;
	vector<long long> arr(n);
	for (i = 0;i < n;i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	for (i = 0;i < n;i++)
	{
		if (ceil((long double)arr[i] / (long double)p) > prev)
		{
			ans += ceil((long double)arr[i] / (long double)p);
			prev = ceil((long double)arr[i] / (long double)p);
		}
		else
		{
			ans += (++prev);
		}





	}



	cout << ans << "\n";




	return 0;
}



