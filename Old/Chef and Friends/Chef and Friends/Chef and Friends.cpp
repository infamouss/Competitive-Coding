// Chef and Friends.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/SEPT16/problems/CHFNFRN

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;


bool isBipartite(vector<vector<int>>& G, int src, vector<int>& colorArr)
{
	colorArr[src] = 1;
	queue <int> q;
	q.push(src);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 0; v < G.size(); ++v)
		{
			if (G[u][v] && colorArr[v] == -1)
			{
				colorArr[v] = 1 - colorArr[u];
				q.push(v);
			}
			else if (G[u][v] && colorArr[v] == colorArr[u])
				return false;
		}
	}
	return true;
}

int main()
{
	int T, N, x, y;
	long M, i;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%ld", &N, &M);
		vector<vector<int>> graph(N, vector<int>(N, 1));
		for (i = 0;i < N;i++)
			graph[i][i] = 0;
		for (i = 0;i < M;i++)
		{
			scanf("%d%d", &x, &y);
			x--;
			y--;
			graph[x][y] = graph[y][x] = 0;
		}
		vector<int> colorArr(N, -1);
		int flag = 0;
		for (i = 0;i < N&&flag == 0;i++)
		{
			if (colorArr[i] == -1)
				if (isBipartite(graph, i, colorArr) == false)
					flag = 1;
		}
		if (flag == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

