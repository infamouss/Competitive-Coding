// Candies.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/candies

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

	long N, i;
	cin >> N;
	vector<long> rating(N + 2);
	rating[0] = 0;
	for (i = 1;i <= N;i++)
		cin >> rating[i];
	rating[i] = 0;
	long long ans = 0;
	long streak = 0;
	for (i = 1;i < N + 1;i++)
	{
		if (rating[i] < rating[i + 1])
		{
			streak++;
			ans += streak;
			
		}
		else if (rating[i] == rating[i + 1])
		{
			//streak++;
			//ans += streak;
			//streak = 0;
			//ans++;


			



		}
		else
		{
			
			int count = 1;
			while (i<N + 1 && rating[i] > rating[i + 1])
			{
				count++;
				i++;
			}
			i--;
			if (i == N)
				count--;
			//cout << i << "\n";
			//ans += (count + 1)*(count) / 2;
			ans += streak;
			ans += count*(count - 1) / 2;
			streak = 0;
			



		}







	}

	ans++;

	

	cout << ans << "\n";













	return 0;
}