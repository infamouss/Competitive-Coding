// So Close Yet So Far.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/LTIME38/problems/CLOSEFAR

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>

using namespace std;




long N;
vector<long> A;

bool dfs(vector<vector<long>>& gph, long startt, long endd, vector<long>& wts, vector<bool>& visited)
{

	if (visited[startt]==true)
		return false;

	visited[startt] = true;

	if (startt == endd)
	{
		wts.push_back(A[startt]);
		return true;
	}
		



	for (long i = 0;i < gph[startt].size();i++)
	{
		long tmp = gph[startt][i];
		bool retval = dfs(gph, tmp, endd, wts, visited);
		if (retval == true)
		{
			wts.push_back(A[startt]);
			return true;
		}
	}


	return false;


}



int main()
{
	long Q, u, v, i, start, endd, tmp, ans;
	char flag;
	scanf("%ld", &N);
	A.push_back(0);
	for (i = 1;i <= N;i++)
	{
		scanf("%ld", &tmp);
		A.push_back(tmp);
	}
		
	vector<vector<long>> gph(N + 1);
	for (i = 0;i < N - 1;i++)
	{
		scanf("%ld%ld", &start, &endd);
		gph[start].push_back(endd);
		gph[endd].push_back(start);
	}

	scanf("%ld", &Q);
	while (Q--)
	{
		scanf(" %c %ld%ld", &flag, &u, &v);
		
		vector<bool> visited(N + 1, false);

		vector<long>wts;

		dfs(gph, u, v, wts, visited);

		if (flag == 'C')
		{
			
			sort(wts.begin(), wts.end());
			ans = wts[1] - wts[0];
			for (i = 1;i < wts.size();i++)
			{
				if (wts[i] - wts[i - 1] < ans)
					ans = wts[i] - wts[i - 1];
			}

		}
		else
		{
			sort(wts.begin(), wts.end());
			ans = wts[wts.size() - 1] - wts[0];
		}
		printf("%ld\n", ans);
	}





	return 0;
}

