#include<stdio.h>


int main()
{
	int t, x1, x2, y1, y2, tmp, ans, m, n, q, i, j;
	int a[501][501] = { 0 };
	scanf("%d", &t);
	while (t)
	{
		scanf("%d%d%d", &n, &m, &q);
		for (i = 1; i <= m; i++)
			for (j = 1; j <= n; j++)
			{
				scanf("%d", &tmp);
				a[j][i] = tmp + a[j-1][i];
			}
				
		while (q)
		{
			scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
			x1;
			x2;
			y1;
			y2;
			ans = 0;
			for (i = y1; i <= y2; i++)
			{
				ans += a[x2][i] - a[x1 - 1][i];
			}
			printf("%d\n", ans);
			q--;
		}
		t--;
	}
	return 0;
}

