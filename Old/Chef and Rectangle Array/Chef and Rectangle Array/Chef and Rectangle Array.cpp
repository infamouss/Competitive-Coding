// Chef and Rectangle ipay.cpp : Defines the entry polong for the console application.
// url : https://www.codechef.com/JUNE16/problems/CHSQip

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <functional>
#include <algorithm>
#include <deque>
using namespace std;


deque<long> Qi;
long ip[1001][1001] = { 0 };
long sum[1001][1001] = { 0 };
long maz[1001][1001] = { 0 };
long maxx[1001][1001] = { 0 };

void prlongKMaxCol(long n, long k, long col)
{
	long i;
	for (i = 1; i <= k; ++i)
	{
		while ((!Qi.empty()) && ip[i][col] >= ip[Qi.back()][col])
			Qi.pop_back();  
		Qi.push_back(i);
	}
	for (; i <= n; ++i)
	{
		maz[i - k][col] = ip[Qi.front()][col];
		while ((!Qi.empty()) && Qi.front() <= i - k)
			Qi.pop_front();  
		while ((!Qi.empty()) && ip[i][col] >= ip[Qi.back()][col])
			Qi.pop_back();
		Qi.push_back(i);
	}
	maz[i - k][col] = ip[Qi.front()][col];
	while (!Qi.empty())
	{
		Qi.pop_back();
	}
}


void prlongKMaxRow(long n, long k, long row)
{
	long i;
	for (i = 1; i <= k; ++i)
	{

		while ((!Qi.empty()) && maz[row][i] >= maz[row][Qi.back()])
			Qi.pop_back();
		Qi.push_back(i);
	}
	for (; i <= n; ++i)
	{
		maxx[row][i-k] = maz[row][Qi.front()];
		while ((!Qi.empty()) && Qi.front() <= i - k)
			Qi.pop_front();
		while ((!Qi.empty()) && maz[row][i] >= maz[row][Qi.back()])
			Qi.pop_back();
		Qi.push_back(i);
	}
	maxx[row][i - k] = maz[row][Qi.front()];
	while (!Qi.empty())
	{
		Qi.pop_back();
	}
}

int main()
{
	long Q, i, j, N, M, a, b;
	long ans;
	
	scanf("%d%d", &N, &M);
	for (i = 1;i <= N;i++)
	{
		for (j = 1;j <= M;j++)
		{
			scanf("%d", &ip[i][j]);
			sum[i][j] = ip[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	scanf("%d", &Q);
	while (Q--)
	{
		scanf("%d%d", &a, &b);
		for (i = 1;i <= M;i++)
		{
			prlongKMaxCol(N, a, i);
		}
		for (i = 1;i <= N - a + 1;i++)
		{
			prlongKMaxRow(M, b, i);
		}
		ans = maxx[1][1] * a*b - sum[a][b];
		for (i = 1;i + a - 1 <= N;i++)
		{
			for (j = 1;j + b - 1 <= M;j++)
			{
				ans = min(ans, maxx[i][j] * a*b - (sum[i + a - 1][j + b - 1] - sum[i - 1][j + b - 1] - sum[i + a - 1][j - 1] + sum[i - 1][j - 1]));
			}
		}
		printf("%ld\n", ans);
	}
	return 0;
}

