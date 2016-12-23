// Cleaning Up.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, m, n, i, tmp;
	scanf("%d", &T);
	while (T--)
	{
		int arr[1000] = { 0 };
		scanf("%d%d", &n, &m);
		for (i = 0;i < m;i++)
		{
			scanf("%d", &tmp);
			arr[tmp - 1]++;
		}
		tmp = 0;
		for (i = 0;i < n;i++)
		{
			if (arr[i] == 0)
			{
				if (tmp == 0)
				{
					printf("%d ", i + 1);
					arr[i] = 1;
				}
				tmp = (tmp + 1) % 2;
			}
		}
		printf("\n");
		for (i = 0;i < n;i++)
		{
			if (arr[i] == 0)
				printf("%d ", i + 1);
		}
		printf("\n");
	}
    return 0;
}

