// Count Steps in Matrix.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

typedef struct nod
{
	int x, y;
} node;



node arr[500 * 500];

long abs(int x)
{
	if (x >= 0)
	{
		return x;
	}
	else
	{
		return -x;
	}
}

int main()
{
	int T, N, i, j;
	long tmp, ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		ans = 0;
		for (i = 0;i < N;i++)
		{
			for (j = 0;j < N;j++)
			{
				scanf("%d",&tmp);
				tmp = tmp - 1;
				arr[tmp].x = i;
				arr[tmp].y = j;
			}
		}
		for (tmp = 1;tmp < N*N;tmp++)
		{
			ans += abs(arr[tmp - 1].x - arr[tmp].x) + abs(arr[tmp - 1].y - arr[tmp].y);
		}
		printf("%ld\n", ans);
	}
    return 0;
}

