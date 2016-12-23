// Count Subarrays.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	long N, prev, current;
	unsigned long long ans, count;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld", &N);
		scanf("%ld", &prev);
		N--;
		ans = 0;
		count = 1;
		while (N--)
		{
			scanf("%ld", &current);
			if (current < prev)
			{
				ans += count*(count + 1) / 2;
				count = 0;
			}
			prev = current;
			count++;
		}
		ans += count*(count + 1) / 2;
		printf("%llu\n", ans);
	}
    return 0;
}

