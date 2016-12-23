// Marbles CC.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


long long combinations(int n, int r)
{
	long long ans = 1;
	int end = (n - r < r) ? n - r : r;
	int i = 1;
	while (i <= end)
	{
		ans *= n + 1 - i;
		ans /= i;
		i++;
	}
	
	return ans;
}



int main()
{
	int T, n, k;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		printf("%lld\n", combinations((n - k) + k - 1, k - 1));
	}
	return 0;
}