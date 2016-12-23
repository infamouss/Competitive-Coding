// Diagonal Difference.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, j, d1 = 0, d2 = 0, tmp;
	scanf("%d", &n);
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			scanf("%d", &tmp);
			if (i == j)
			{
				d1 += tmp;
			}
			if (i == n - 1 - j)
			{
				d2 += tmp;
			}
		}
	}
	printf("%d", abs(d1 - d2));


	return 0;
}

