// Sum of Digits.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, ans;
	long N;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld", &N);
		ans = 0;
		while (N)
		{
			ans += N % 10;
			N /= 10;
		}
		printf("%d\n", ans);
	}
    return 0;
}

