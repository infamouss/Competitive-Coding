// Chocolate Boxes.cpp : Defines the entry polong for the console application.
// url : https://www.hackerrank.com/contests/holi-code/challenges/chocolate-boxes

#include <stdio.h>



int main()
{
	int T;
	long N, val[100001] = { 0 }, pos[100001] = { 0 }, i, ans, tmp1;
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%ld", &N);
		for (i = 1;i <= N;i++)
		{
			scanf("%ld", &val[i]);
			pos[val[i]] = i;
		}
		for (i = 1;i <= N;i++)
		{
			if (val[i] != i)
			{
				tmp1 = val[i];
				val[i] = val[pos[i]];
				val[pos[i]] = tmp1;
				pos[tmp1] = pos[i];
				pos[i] = val[i];
				ans++;
			}
		}
		printf("%ld\n", ans);
	}
	return 0;
}

