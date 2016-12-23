// Who dares to be a millionaire.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, i, N, rights;
	long w[1001], maxRewards;
	char input[1001], correct[1001];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		scanf("%s%s", input, correct);
		i = 0;
		maxRewards = -1;
		rights = 0;
		while (input[i] != '\0')
		{
			if (input[i] == correct[i])
			{
				rights++;
			}
			i++;
		}

		for (i = 0;i <= N;i++)
		{
			scanf("%ld", &w[i]);
			if (maxRewards < w[i] && i <= rights)
			{
				maxRewards = w[i];
			}
		}
		printf("%ld\n", (rights==N)?w[N]:maxRewards);
	}
    return 0;
}

