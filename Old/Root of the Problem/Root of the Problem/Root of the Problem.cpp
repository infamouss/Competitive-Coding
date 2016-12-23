// Root of the Problem.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	int ans, id, sum, n;
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d%d", &id, &sum);
			ans += id - sum;
		}
		printf("%d\n", ans);
	}
	return 0;
}