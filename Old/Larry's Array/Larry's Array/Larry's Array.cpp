// Larry's Array.cpp : Defines the entry point for the console application.
// url:https://www.hackerrank.com/challenges/larrys-array

#include <stdio.h>


int main()
{
	int T, N, arr[1000], i, j, flag;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (i = 0;i < N;i++)
		{
			scanf("%d", &arr[i]);
		}
		flag = 0;
		for (i = 0;i < N - 2 && flag == 0;i++)
		{
			flag = 1;
			if (arr[i] <= arr[i + 1] && arr[i + 1] <= arr[i + 2])
			{
				flag = 0;
			}
			else if (arr[i + 1] <= arr[i + 2] && arr[i + 2] <= arr[i])
			{
				flag = 0;
			}
			else if (arr[i + 2] <= arr[i] && arr[i] <= arr[i + 1])
			{
				flag = 0;
			}
		}

		if (flag == 0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}

	}



	return 0;
}

