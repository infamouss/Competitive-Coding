// B.cpp : Defines the entry point for the console application.
//

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


long long solve(long x, long y, long len, vector<vector<int>>&grd,long R,long C)
{

	long i;
	for (i = 0;i < len;i++)//col
		if (grd[x+len-1][y+i] == 1)
			return 0;

	for (i = 0;i < len;i++)//row
		if (grd[x+i][y+len-1] == 1)
			return 0;



	return 1;


}




int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	long T, lp;
	long long ans;
	cin >> T;

	long R, C, K, i, j, x, y;
	
	for (lp = 1;lp <= T;lp++)
	{

		
		
		ans = 0;
		cin >> R >> C >> K;
		vector<vector<int>> grd(R, vector<int>(C, 0));
		for (i = 0;i < K;i++)
		{
			cin >> x >> y;
			grd[x][y] = 1;
		}



		for (i = 0;i < R;i++)
		{
			for (j = 0;j < C;j++)
			{
				int len = 1;
				
				
				while (((i + len <= R) && (j + len <= C)) && solve(i, j, len, grd, R, C))
				{
					ans++;

					//cout << i << " " << j << " " << len << "\n";

					len++;
				}

				

			}
		}










		cout << "Case #" << lp << ": " << ans << "\n";
	}
	return 0;
}