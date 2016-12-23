// Chef and calculation.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/SEPT16/problems/RESCALC

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
	int T, N, tie, index, i, j;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		vector<int> scores(N);
		for (i = 0;i < N;i++)
		{
			vector<int> items(6, 0);
			int tmp;
			scanf("%d", &scores[i]);
			for (j = 0;j < scores[i];j++)
			{
				scanf("%d", &tmp);
				items[tmp - 1]++;
			}
			sort(items.begin(), items.end());
			scores[i] += 4 * items[0];
			items[1] -= items[0];
			items[2] -= items[0];
			scores[i] += 2 * items[1];
			items[2] -= items[1];
			scores[i] += 1 * items[2];
		}
		index = tie = 0;
		for (i = 1;i < N;i++)
		{
			if (scores[i] > scores[index])
			{
				tie = 0;
				index = i;
			}
			else if (scores[i] == scores[index])
				tie = 1;
		}
		if (tie == 1)
			printf("tie\n");
		else if (index == 0)
			printf("chef\n");
		else
			printf("%d\n", index + 1);	
	}
	return 0;
}

