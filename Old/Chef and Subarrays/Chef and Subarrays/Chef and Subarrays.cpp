// Chef and Subarrays.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/COOK77/problems/CHEFARRB

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

	long T;
	cin >> T;
	while (T--)
	{
		long N, K, i;
		cin >> N >> K;
		vector<long> arr(N);
		for (i = 0;i < N;i++)
			cin >> arr[i];
		long lastIndex = 0, start = 0, sum = 0, current = 0, ans = 0, rev;
		

		while (current<N)
		{
			sum = 0;
			while (current < N && sum < K)
			{
				sum = sum | arr[current];
				current++;
			}
			
			if (sum >= K)
			{
				current--;
				rev = current;
				long sum2 = 0;
				while (rev >= lastIndex && sum2 <= K)
				{
					sum2 = sum2 | arr[rev];
					rev--;
				}
				rev++;
				ans += (N - current)*(rev+1);
			}
			//current++;
		}
		

		cout << ans << "\n";



	}










	return 0;
}


