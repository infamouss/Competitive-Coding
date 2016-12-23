// Angry Professor.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, N, K, tmp, count;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &K);
		count = 0;
		for (int i = 0;i < N;i++)
		{
			scanf("%d", &tmp);
			if (tmp <= 0)
			{
				count++;
			}
		}
		printf("%s\n", (count < K) ? "YES" : "NO");
	}
	return 0;
}

