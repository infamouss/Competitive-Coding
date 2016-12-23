#include "stdafx.h"
#include<stdio.h>
int main()
{
	int t, i, r[101], g[101], b[101], j, R, G, B, M, ans[1000], sr=0,sg=0,sb=0;
	scanf_s("%d", &t); 
	for (i = 0; i < t; i++)
	{
		scanf_s("%d%d%d%d",&R,&G,&B,&M);
		scanf_s("%d", &r[1]);
		sr = r[0] = r[1];
		for (j = 2; j <= R; j++)
		{
			scanf_s("%d", &r[j]);
			if (r[0] < r[j])
				r[0] = r[j];
			sr = sr + r[j];
		}
		scanf_s("%d", &g[1]);
		sg = g[0] = g[1];
		for (j = 2; j <= G; j++)
		{
			scanf_s("%d", &g[j]);
			if (g[0] < g[j])
				g[0] = g[j];
			sg = sg + g[j];
		}
		scanf_s("%d", &b[1]);
		sb = b[0] = b[1];
		for (j = 2; j <= B; j++)
		{
			scanf_s("%d", &b[j]);
			if (b[0] < b[j])
				b[0] = b[j];
			sb = sb + b[j];
		}
		for (j = 0; j < M; j++)
		{
			if (sr >= sg && sr >= sb)
			{
				sr = 0;
				r[0] = r[0] / 2;
				for (j = 1; j <= R; j++)
				{
					r[j] = r[j] / 2;
					sr = sr + r[j];
				}
			}
			else if (sg >= sr && sg >= sb)
			{
				sg = 0;
				g[0] = g[0] / 2;
				for (j = 1; j <= G; j++)
				{
					g[j] = g[j] / 2;
					sg = sg + g[j];
				}
			}
			else
			{
				sb = 0;
				b[0] = b[0] / 2;
				for (j = 1; j <= B; j++)
				{
					b[j] = b[j] / 2;
					sb = sb + b[j];
				}
			}
		}			
		if (r[0] >= g[0] && r[0] >= b[0])
			ans[i] = r[0];
		else if (g[0] >= r[0] && g[0] >= b[0])
			ans[i] = g[0];
		else
			ans[i] = b[0];
	}
	for (i = 0; i < t; i++)
		printf("%d\n",ans[i]);
	return 0;
}