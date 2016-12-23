#include<stdio.h>


int multPoly(int ans[], int expAns, int expPoly, int tmp[]);


int main()
{
	int m, n, ans[2001] = { 1 }, tmp[2001] = { 0 }, i, min, max, expAns = 0, expPoly;
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &min, &max);
		expPoly = max - min;
		n = n - min;
		expAns = multPoly(ans, expAns, expPoly, tmp);
	}
	if (n >= 0)
	{
		printf("%d", ans[n]);
	}
	else
	{
		printf("0");
	}
	return 0;
}


int multPoly(int ans[], int expAns, int expPoly, int tmp[])
{
	int i, j;
	for (i = 0; i <= expAns; i++)
		for (j = 0; j <= expPoly; j++)
		{
			tmp[i + j] = tmp[i + j] + ans[i];
		}
	expAns = expAns + expPoly;
	for (i = 0; i <= expAns; i++)
	{
		ans[i] = tmp[i];
		tmp[i] = 0;
	}
	return expAns;
}