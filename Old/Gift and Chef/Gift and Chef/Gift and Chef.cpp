// Gift and Chef.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/NOV16/problems/GIFTCHEF

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

#define MOD 1000000007

void computeLPSArray(string &pat, int M, vector<int> &lps)
{
	int len = 0;

	lps[0] = 0;
	int i = 1;
	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
			{
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}


void KMPSearch(string& txt, string& pat, vector<int>& pos)
{
	int M = pat.size();
	int N = txt.size();
	vector<int> lps(M);
	computeLPSArray(pat, M, lps);
	int i = 0;
	int j  = 0;
	while (i < N)
	{
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}
 
		if (j == M)
		{
			pos[i - j] = 1;
			j = lps[j-1];
		}
		else if (i < N && pat[j] != txt[i])
		{
			if (j != 0)
				j = lps[j-1];
			else
				i = i+1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	/*long T, lp;
	long long ways;
	cin >> T;
	for (lp = 1;lp <= T;lp++)
	{
	cout << "Case #" << lp << ": " << ways << "\n";
	}*/


	int T;
	cin >> T;
	while (T--)
	{
		long i;
		string a, b;
		cin >> a >> b;
		vector<int> pos(a.size(), 0);
		KMPSearch(a, b, pos);
		vector<long long> dp(a.size() + 1), ways(a.size() + 1);
		dp[a.size()] = ways[a.size()] = 0;
		for (i = a.size() - 1;i >= 0;i--)
		{
			if (pos[i] == 1)
			{
				ways[i] = dp[i + b.size()] + 1;
				ways[i] %= MOD;
				dp[i] = dp[i + 1] + ways[i];
				dp[i] %= MOD;
			}
			else
			{
				ways[i] = ways[i + 1];
				dp[i] = dp[i + 1];
			}	
		}
		cout << dp[0] << "\n";
	}
	return 0;
}
