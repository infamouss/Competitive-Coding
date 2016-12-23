// Supritha and her Wine bottles.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<stdlib.h>




int wineBottles(int bottles[], int start, int end, int multiplier);

int memo[500][500][500] = { 0 };
int main()
{
	int n, bottles[500], i, ans, j, k;
	scanf("%d", &n);
	/*for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
				memo[i][j][k] = 0;*/
	for (i = 0; i < n; i++)
		scanf("%d", &bottles[i]);
	ans = wineBottles(bottles, 0, n - 1, 1);
	printf("%d\n", ans);
	return 0;
}

int wineBottles(int bottles[], int start, int end, int multiplier)
{
	int ans, c1, c2;
	if (memo[start][end][multiplier - 1] != 0)
	{
		ans = memo[start][end][multiplier - 1];
	}
	else
	{
		if (start == end)
		{
			ans = bottles[start] * multiplier;
		}
		else
		{
			c1 = bottles[start] * multiplier + wineBottles(bottles, start + 1, end, multiplier + 1);
			c2 = bottles[end] * multiplier + wineBottles(bottles, start, end - 1, multiplier + 1);
			ans = (c1>c2) ? c1 : c2;
		}
		memo[start][end][multiplier - 1] = ans;
	}
	return ans;
}