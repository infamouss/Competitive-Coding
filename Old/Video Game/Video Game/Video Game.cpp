// Video Game.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/ZCOPRAC/problems/ZCO14001

#include <stdio.h>


int main()
{
	long N, H, arr[100000], i;
	int load, operation;
	scanf("%ld%ld", &N, &H);
	for (i = 0;i < N;i++)
	{
		scanf("%ld", &arr[i]);
	}
	i = 0;
	load = 0;
	scanf("%d", &operation);
	while (operation != 0)
	{
		switch (operation)
		{
		case 1:
			if (i > 0)
			{
				i--;
			}
			break;
		case 2:
			if (i < N - 1)
			{
				i++;
			}
			break;
		case 3:
			if (arr[i] != 0 && load == 0)
			{
				arr[i]--;
				load = 1;
			}
			break;
		case 4:
			if (arr[i] + 1 <= H&&load == 1)
			{
				arr[i]++;
				load = 0;
			}
		}
		scanf("%d", &operation);
	}
	for (i = 0;i < N;i++)
	{
		printf("%ld ", arr[i]);
	}
	return 0;
}

