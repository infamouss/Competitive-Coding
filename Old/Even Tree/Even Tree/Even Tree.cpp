// Even Tree.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/even-tree

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int assighWts(vector<vector<int>>& graph, vector<int>& isVisited, vector<int>& wts, int root)
{
	if (graph[root].size() == 1)
	{
		wts[root] = 1;
		isVisited[root] = 1;
	}
	else
	{
		wts[root] = 1;
		isVisited[root] = 1;
		for (int i = 0;i < graph[root].size();i++)
			if (isVisited[graph[root][i]] == 0)
				wts[root] += assighWts(graph, isVisited, wts, graph[root][i]);
			
	}
	return wts[root];
}


int main()
{
	int N, K, i, x, y, ans = -1;
	scanf("%d%d", &N, &K);
	vector<vector<int>> graph(N);
	for (i = 0;i < K;i++)
	{
		scanf("%d%d", &x, &y);
		x--;y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	vector<int> isVisited(N, 0), wts(N, 0);
	assighWts(graph, isVisited, wts, 0);
	for (i = 0;i < N;i++)
		if (wts[i] % 2 == 0)
			ans++;
	printf("%d\n", ans);
	return 0;
}

