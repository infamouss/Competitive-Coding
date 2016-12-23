// Devu and an Array.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

typedef long long lli;

int main()
{
	lli N, Q, A, max, min, t;
	scanf("%lld%lld", &N, &Q);
	N--;
	scanf("%lld", &A);
	max = min = A;
	while (N--)
	{
		scanf("%lld", &A);
		if (min > A)
		{
			min = A;
		}
		if (max < A)
		{
			max = A;
		}
	}
	while (Q--)
	{
		scanf("%lld", &t);
		printf("%s\n", (min <= t&&t <= max) ? "Yes" : "No");
	}
	return 0;
}

