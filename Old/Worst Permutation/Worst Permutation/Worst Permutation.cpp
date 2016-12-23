// Worst Permutation.cpp : Defines the entry point for the console application.
//

#include<stdio.h>


int main()
{
	int n, k, a[100000], i, j, numSwap, max, tmp, index;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	if (k >= n - 1)
	{
		for (i = 0; i < n; i++)
		{
			printf("%d ", n - i);
		}
	}
	else
	{
		for (i = numSwap = 0; i < n - 1 && numSwap < k; i++)
		{
			if (a[i] != n - i)
			{
				max = a[i];
				index = i;
				for (j = i + 1; j < n; j++)
				{
					if (max < a[j])
					{
						max = a[j];
						index = j;
					}
				}
				tmp = a[i];
				a[i] = a[index];
				a[index] = tmp;
				numSwap++;
			}
		}
		for (i = 0; i < n; i++)
		{
			printf("%d ", a[i]);
		}
	}
	return 0;
}