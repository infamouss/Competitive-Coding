// Hackonacci Matrix Rotations.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/w27/challenges/hackonacci-matrix-rotations

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


	/*{
		long long i, j;
		vector<long long> arr(10001);
		arr[1] = 1, arr[2] = 2 % 2, arr[3] = 3 % 2;
		for (i = 4;i <= 10000;i++)
			arr[i] = (arr[i - 1] + 2 * arr[i - 2] + 3 * arr[i - 3]) % 2;
		for (i = 1;i <= 100;i++)
		{
			cout << i << " " << ((arr[i]) ? "odd" : "even") << "\t";
		cout << i + 14 << " " << ((arr[i + 14]) ? "odd" : "even") << "\n";
		}
		for (i = 1;i <= 10;i++)
			for (j = 1;j <= 10;j++)
				cout << i << " " << j << " " << ((arr[i*i*j*j])?"odd":"even") << "\n";
	}*/
	

	long long N, Q, i, j;
	cin >> N >> Q;
	vector<vector<int>> arr(N + 1, vector<int>(N + 1));
	for (i = 1;i <= N;i++)
	{
		for (j = 1;j <= N;j++)
		{
			switch ((i*i*j*j) % 14)
			{
			case 1:
				arr[i][j] = 1;
				break;
			case 2:
				arr[i][j] = 0;
				break;
			case 3:
				arr[i][j] = 1;
				break;
			case 4:
				arr[i][j] = 0;
				break;
			case 5:
				arr[i][j] = 0;
				break;
			case 6:
				arr[i][j] = 1;
				break;
			case 7:
				arr[i][j] = 1;
				break;
			case 8:
				arr[i][j] = 1;
				break;
			case 9:
				arr[i][j] = 0;
				break;
			case 10:
				arr[i][j] = 1;
				break;
			case 11:
				arr[i][j] = 0;
				break;
			case 12:
				arr[i][j] = 0;
				break;
			case 13:
				arr[i][j] = 1;
				break;
			case 0:
				arr[i][j] = 1;
				break;
			}
		}
	}

	vector<long long> ans(4, 0);

	
	for (i = 1;i <= N;i++)
	{
		for (j = 1;j <= N;j++)
		{
			//90
			if (arr[i][j] != arr[N + 1 - j][i])
				ans[1]++;
			//180
			if (arr[i][j] != arr[N + 1 - i][N + 1 - j])
				ans[2]++;
			//270
			if (arr[i][j] != arr[j][N + 1 - i])
				ans[3]++;
		}
	}
	

	while (Q--)
	{
		long long angle;
		cin >> angle;
		cout << ans[(angle % 360) / 90] << "\n";
	}
	return 0;
}

