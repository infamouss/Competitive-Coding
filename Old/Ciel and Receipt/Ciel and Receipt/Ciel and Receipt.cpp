// Ciel and Receipt.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, ans, mul;
	long p;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld", &p);
		ans = 0;
		mul = 2048;
		while (p != 0)
		{
			ans += p / mul;
			p %= mul;
			mul /= 2;
		}
		printf("%d\n", ans);
	}
    return 0;
}

