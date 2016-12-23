// Project Euler 11 LargestProductInAGrid.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int arr[20][20], i, j;
	long ans, tmp;
	for (i = 0;i < 20;i++)
		for (j = 0;j < 20;j++)
			scanf("%d", &arr[i][j]);
	ans = arr[0][0] * arr[1][1] * arr[2][2] * arr[3][3];
	for (i = 0;i < 20;i++)
	{
		for (j = 0;j < 20;j++)
		{
			if (i < 17)//vertical
			{
				tmp= arr[i][j] * arr[i+1][j] * arr[i+2][j] * arr[i+3][j];
			}
			if (ans < tmp)
				ans = tmp;
			if (j < 17)//horizontal
			{
				tmp = arr[i][j] * arr[i][j + 1] * arr[i][j + 2] * arr[i][j + 3];
			}
			if (ans < tmp)
				ans = tmp;
			if (i < 17 && j < 17)//diagonal
			{
				tmp = arr[i][j] * arr[i + 1][j + 1] * arr[i + 2][j + 2] * arr[i + 3][j + 3];
			}
			if (ans < tmp)
				ans = tmp;
			if (i >= 3 && j < 17)//anti-diagonal
			{
				tmp = arr[i][j] * arr[i - 1][j + 1] * arr[i - 2][j + 2] * arr[i - 3][j + 3];
			}
			if (ans < tmp)
				ans = tmp;
		}
	}
	printf("%ld", ans);
	return 0;
}

