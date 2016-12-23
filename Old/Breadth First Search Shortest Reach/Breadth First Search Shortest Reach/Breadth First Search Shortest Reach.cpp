// Breadth First Search Shortest Reach.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/bfsshortreach

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int q, x, y, start;
	long n, m, i, j;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%ld%ld", &n, &m);
		vector<vector<int>> graph(n);
		queue<int> q;
		for (i = 0;i < m;i++)
		{
			scanf("%d%d", &x, &y);
			x--;y--;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		scanf("%d", &start);
		start--;
		vector<int> dist(n, -1);
		q.push(start);
		q.push(-1);
		int level = 6;
		dist[start] = 0;
		while (q.front() != -1)
		{
			int node = q.front();
			q.pop();
			for (i = 0;i < graph[node].size();i++)
			{
				if (dist[graph[node][i]] == -1)
				{
					q.push(graph[node][i]);
					dist[graph[node][i]] = level;
				}
			}
			if (q.front() == -1)
			{
				q.pop();
				q.push(-1);
				level += 6;
			}
		}
		for (i = 0;i < n;i++)
			if (i != start)
				printf("%d ", dist[i]);
		
		printf("\n");
	}
	return 0;
}

