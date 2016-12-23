// The Maximum Subarray.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/maxsubarray

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
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--)
	{
		long N, i, con = 0;
		int max = -10001;
		cin >> N;
		vector<int> arr(N);
		for (i = 0;i < N;i++)
		{
			cin >> arr[i];
			if (arr[i] > max)
				max = arr[i];
			if (arr[i] > 0)
				con += arr[i];
		}
		if (max <= 0)
			cout << max << " " << max << "\n";
		else
		{
			long sum = 0, prev = 0;

			for (i = 0;i < N;i++)
			{
				sum += arr[i];
				if (sum > prev)
				{
					prev = sum;
				}
				else if (sum < 0)
				{
					sum = 0;
				}
			}
			cout << prev << " " << con << "\n";
		}
	}
	return 0;
}