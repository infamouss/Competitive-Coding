// Edit Distance Revisited.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/DEC16/problems/EDIT

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


int editDistDP(string str1, string str2)
{
	// Create a table to store results of subproblems
	int m = str1.size(), n = str2.size();
	//int dp[m + 1][n + 1];
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	// Fill d[][] in bottom up manner
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			// If first string is empty, only option is to
			// isnert all characters of second string
			if (i == 0)
				dp[i][j] = j;  // Min. operations = j

							   // If second string is empty, only option is to
							   // remove all characters of second string
			else if (j == 0)
				dp[i][j] = i; // Min. operations = i

							  // If last characters are same, ignore last char
							  // and recur for remaining string
			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			// If last character are different, consider all
			// possibilities and find minimum
			else
				dp[i][j] = 1 + min(dp[i][j - 1],  // Insert
					dp[i - 1][j],  // Remove
					dp[i - 1][j - 1]); // Replace
		}
	}

	return dp[m][n];
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
		string s, t;
		cin >> s;
		cin >> t;
		int I, D, W, R[26][26], i, j;
		cin >> I >> D >> W;
		for (i = 0;i < 26;i++)
			for (j = 0;j < 26;j++)
				cin >> R[i][j];





	}









	return 0;
}


