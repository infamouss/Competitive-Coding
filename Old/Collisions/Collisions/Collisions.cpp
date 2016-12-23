// Collisions.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/LTIME37/problems/LCOLLIS

#include <stdio.h>

char ip[11][11];
int main()
{
	int T, M, N, ans, i, j, count;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &M);
		for (i = 0;i < N;i++)
		{
			scanf("%s", ip[i]);
		}
		ans = 0;
		for (i = 0;i < M;i++)
		{
			count = 0;
			for (j = 0;j < N;j++)
			{
				if (ip[j][i] == '1')
					count++;
			}
			if (count > 1)
				ans += (count*(count - 1)) / 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}

