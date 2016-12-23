// Chef and Numbers.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/COOK72/problems/CHEFFED

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

int summ(int N)
{
	int ans = 0;
	while (N > 0)
	{
		ans += N % 10;
		N /= 10;
	}
	return ans;
}
int main()
{
	int N, i, ans = 0;
	scanf("%d", &N);
	
	for (i = max(0, N - 200);i <N+1;i++)
	{
		int si = summ(i);
		if (i + si + summ(si) == N)
			ans++;
	}
	printf("%d", ans);
	return 0;
}

