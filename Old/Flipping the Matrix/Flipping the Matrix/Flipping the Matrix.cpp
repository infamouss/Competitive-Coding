// Flipping the Matrix.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/world-codesprint-6/challenges/flipping-the-matrix

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
	int q, n, i, j;
	long ans;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d", &n);
		vector<vector<int>> arr(2 * n, vector<int>(2 * n));
		for (i = 0;i < 2 * n;i++)
			for (j = 0;j < 2 * n;j++)
				scanf("%d", &arr[i][j]);
		for (i = ans = 0;i < n;i++)
			for (j = 0;j < n;j++)
				ans += max(max(arr[i][j], arr[i][2 * n - 1 - j]), max(arr[2 * n - 1 - i][j], arr[2 * n - 1 - i][2 * n - 1 - j]));
		printf("%ld\n", ans);
	}
	return 0;
}

