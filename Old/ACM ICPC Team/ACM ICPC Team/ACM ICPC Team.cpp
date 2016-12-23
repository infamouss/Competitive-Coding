// ACM ICPC Team.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char **arr;
	int i, j, N, M, maxAns = -1, numTeams = 0, tmp, k;
	scanf("%d%d", &N, &M);
	arr = (char**)malloc(sizeof(char*)*N);
	for (i = 0;i < N;i++)
	{
		arr[i] = (char*)malloc(sizeof(char)*(M+1));
		scanf("%s", arr[i]);
	}
	
	for (i = 0;i < N - 1;i++)
	{
		for (j = i + 1;j < N;j++)
		{
			tmp = 0;
			for (k = 0;k < M;k++)
			{
				if (arr[i][k] == '1' || arr[j][k] == '1')
				{
					tmp++;
				}
			}
			if (tmp > maxAns)
			{
				maxAns = tmp;
				numTeams = 1;
			}
			else if(tmp==maxAns)
			{
				numTeams++;
			}
		}
	}
	printf("%d\n%d", maxAns, numTeams);

	for (i = 0;i < N;i++)
	{
		free(arr[i]);
	}
	free(arr);
	return 0;
}

