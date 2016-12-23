// Algorithmic Crush.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/crush

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

long long arr[10000001] = { 0 };

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
	
	long N, M, a, b, k;
	cin >> N >> M;
	while (M--)
	{
		cin >> a >> b >> k;
		arr[a - 1] += k;
		arr[b] -= k;
	}
	a = arr[0];
	for (k = 0;k < N;k++)
	{
		if (arr[k] > a)
			a = arr[k];
		arr[k + 1] += arr[k];
	}
	cout << a << "\n";
	return 0;
}

