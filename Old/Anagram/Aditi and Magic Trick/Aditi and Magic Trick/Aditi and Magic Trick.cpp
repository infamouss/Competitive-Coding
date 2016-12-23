// Aditi and Magic Trick.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	long T;
	unsigned long long N, ans, a, b, term;
	scanf("%ld", &T);
	while (T--)
	{
		scanf("%llu", &N);
		a = 0;
		b = 1;
		term = a + b;
		ans = -1;
		while (term <= N)
		{
			term = a + b;
			a = b;
			b = term;
			ans++;
		}
		printf("%llu\n", ans);
	}
    return 0;
}

