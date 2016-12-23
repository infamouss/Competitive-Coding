// Lock-Free Stack.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/LTIME39/problems/LFSTACK

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, i, total = 0;
		scanf("%d", &N);
		vector<int> ip[1000];
		for (i = 0;i < N;i++)
		{
			int j, n, tmp;
			scanf("%d", &n);
			total += n;
			while (n--)
			{
				scanf("%d", &tmp);
				ip[i].push_back(tmp);
			}
		}
		vector<int> stk;
		for (i = 0;i < total;i++)
		{
			int tmp;
			scanf("%d", &tmp);
			stk.push_back(tmp);
		}
		reverse(stk.begin(), stk.end());
		while (stk.size() > 0)
		{
			for (i = 0;i < N;i++)
			{
				if (!ip[i].empty() && ip[i][ip[i].size() - 1] == stk[stk.size() - 1])
				{
					ip[i].erase(ip[i].end() - 1);
				}
			}
			stk.erase(stk.end() - 1);
		}
		int flag = 0;
		for (i = 0;i < N&&flag==0;i++)
		{
			if (!ip[i].empty())
			{
				flag = 1;
				ip[i].erase(ip[i].begin(), ip[i].end());
			}
				
		}
		if (flag == 0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}

