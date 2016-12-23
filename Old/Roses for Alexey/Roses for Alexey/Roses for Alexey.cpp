// Roses for Alexey.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/DEC16/problems/ALEXROSE

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
		int N, numFlowers, i, numBouquets, j;
		long long tmp, ans = 0;
		unordered_map<long long, long long> mp;
		
		cin >> N >> numFlowers;
		numBouquets = N / numFlowers;
		for (i = 0;i < N;i++)
		{
			cin >> tmp;
			
			//it = mp.find(tmp);

			if (mp.find(tmp) == mp.end())
			{
				mp[tmp] = 1;
			}
			else
			{
				mp[tmp] = mp[tmp] + 1;
			}


		}
		vector<pair<long long, long long>> arr;
		//vector<long long> arr;

		for (unordered_map<long long, long long>::const_iterator it = mp.begin(); it != mp.end(); it++)
		{
			if ((it->second) >= numFlowers)
			{
				numBouquets -= (it->second) / numFlowers;
			}
			if ((it->second) % numFlowers != 0)
			{
				arr.push_back(make_pair(it->first, it->second % numFlowers));
				//arr.push_back(it->second%numFlowers);
			}
		}
		sort(arr.rbegin(), arr.rend());
		N = numBouquets*numFlowers;

		vector<long long> dp(arr.size());
		
		dp[0] = numFlowers - arr[0].second;
		long long remaining = N - arr[0].second, needed = numFlowers - arr[0].second;

		

		for (i = 1;i < arr.size();i++)
		{



			if (remaining < numFlowers)
			{
				//dissolve
				needed -= arr[i].second;
				dp[i] = dp[i - 1] + arr[i].second;
				remaining -= arr[i].second;
			}
			else
			{
				//can fill
				dp[i] = dp[i - 1] + numFlowers - arr[i].second;
				remaining -= arr[i].second;
			}



		}













		
		cout << ans << "\n";
	}









	return 0;
}


