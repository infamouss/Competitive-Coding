// Largest Permutation.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/largest-permutation

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



	long N, i, tmp;
	long long K;
	cin >> N >> K;
	vector<long> arr(N + 1), storedIndices(N + 1);
	for (i = 1;i <= N;i++)
	{
		cin >> arr[i];
		//arr[i] = tmp;
		storedIndices[N + 1 - arr[i]] = i;
		
	}

	














	for (i = 1;i <= N;i++)
		cout << arr[i] << " ";



	return 0;
}
