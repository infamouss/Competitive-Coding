// First and Last Digit.cpp : Defines the entry point for the console application.
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
		ans = N % 10;
		while (N / 10)
		{
			N /= 10;
		}
		ans += N;
		printf("%d\n", ans);
	}
    return 0;
}

