#include "stdafx.h"
#include<stdio.h>
int main()
{
	int a0[100][100], a90[100][100], a180[100][100], a270[100][100];
	char  flg90 = 0, flg180 = 0, flg270 = 0, i, j, k;
	short int n, mm[100], m;
	scanf_s("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf_s("%d", &a0[i][j]);
		}
	}
	for (k = 0; k < m; k++)
	{
		scanf_s("%d", &mm[k]);
	}
	for (k = 0; (k < m) && ((flg90 == 0) || (flg180 == 0) || (flg270 == 0)); k++)
	{
		if ((mm[k] % 360 == 90) && (flg90 == 0))
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					a90[j][n - 1 - i] = a0[i][j];
				}
			}
			flg90 = 1;
		}
		else if ((mm[k] % 360 == 180) && (flg180 == 0))
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					a180[n - 1 - i][n - 1 - j] = a0[i][j];
				}
			}
			flg180 = 1;
		}
		else if ((mm[k] % 360 == 270) && (flg270 == 0))
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					a270[n - 1 - j][i] = a0[i][j];
				}
			}
			flg270 = 1;
		}
	}
	for (k = 0; k < m; k++)
	{
		if (mm[k] % 360 == 0)
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					printf("%d\t", a0[i][j]);
				}
				printf("\n");
			}
		}
		else if (mm[k] % 360 == 90)
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					printf("%d\t", a90[i][j]);
				}
				printf("\n");
			}
		}
		else if (mm[k] % 360 == 180)
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					printf("%d\t", a180[i][j]);
				}
				printf("\n");
			}
		}
		else if (mm[k] % 360 == 270)
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					printf("%d\t", a270[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}