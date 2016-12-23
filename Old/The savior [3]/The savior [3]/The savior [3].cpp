// The savior [3].cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int t;
	int n, i, j;
	long arr[1001], ans;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		ans = 0;
		for (i = 0;i < n;i++)
			scanf("%ld", &arr[i]);
		for (i = 0;i < n - 1;i++)
		{
			for (j = i + 1;j < n;j++)
			{
				if (arr[i] != arr[j] && (arr[i] + arr[j]) % 2 == 0)
				{
					ans++;
				}
			}
		}
		printf("%ld\n", ans);
	}
	return 0;
}

