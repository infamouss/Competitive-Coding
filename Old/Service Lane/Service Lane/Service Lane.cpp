// Service Lane.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int T, tmp;
	long N, i, start, end;
	long int* lane[3];
	scanf("%ld%d", &N, &T);
	lane[1] = (long int*)malloc(sizeof(long int)*(N));
	lane[2] = (long int*)malloc(sizeof(long int)*(N));
	scanf("%d", &tmp);
	lane[2][0] = lane[1][0] = lane[0][0] = 0;
	switch (tmp)
	{
	case 3:
		lane[2][0] = 1;
	case 2:
		lane[1][0] = 1;
	}
	for (i = 1;i < N;i++)
	{
		lane[1][i] = lane[1][i - 1];
		lane[2][i] = lane[2][i - 1];
		scanf("%d", &tmp);
		switch (tmp)
		{
		case 3:
			lane[2][i]++;
		case 2:
			lane[1][i]++;
		}
	}


	for (i = 0;i < T;i++)
	{
		scanf("%ld%ld", &start, &end);
		if (start == 0)
		{
			if (lane[2][end] == end + 1)
			{
				printf("3\n");
			}
			else if (lane[1][end] == end + 1)
			{
				printf("2\n");
			}
			else
			{
				printf("1\n");
			}
		}
		else
		{
			if (lane[2][end] - lane[2][start - 1] == end - start + 1)
			{
				printf("3\n");
			}
			else if (lane[1][end]- lane[1][start - 1] == end - start + 1)
			{
				printf("2\n");
			}
			else
			{
				printf("1\n");
			}
		}
	}
	free(lane[1]);
	free(lane[2]);
	return 0;
}

