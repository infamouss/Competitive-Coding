// Perfect Cakes.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <string>

using namespace std;


int findImperfectCake(int N, int M, int numBoxesCompared[100],
	int boxesLeft[100][1000], int boxesRight[100][1000], char compRes[100])
{

	set<int> vals;
	for (int i = 1;i <= N;i++)
		vals.insert(i);
	return 0;
}




int main()
{
	int T, N, M, i, j, wts;
	char op;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &M);
		set<int> vals;
		for (i = 1;i <= N;i++)
		{
			vals.insert(i);
		}

		for (i = 0;i < M;i++)
		{
			scanf("%d", &wts);
			vector<int> left(wts), right(wts);
			for (j = 0;j < wts;j++)
			{
				scanf("%d", &left[j]);
			}
			for (j = 0;j < wts;j++)
			{
				scanf("%d", &right[j]);
			}
			int z;
			string sz;
			
			cin >> sz;
			if (sz[0] == '=')
			{
				for (j = 0;j < wts;j++)
				{
					if (vals.find(left[j]) != vals.end())
						vals.erase(left[j]);
				}
				for (j = 0;j < wts;j++)
				{
					if (vals.find(right[j]) != vals.end())
					vals.erase(right[j]);
				}
			}






		}

		if (vals.size() == 1)
		{
			set<int>::iterator it = vals.begin();
			printf("%d\n", *it);
		}
		else
		{
			printf("0\n");
		}


	}


	while(T--)






	return 0;
}

