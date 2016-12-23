// Find Digits.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	long long num, pow10, tmp;
	int dig, ans;
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%lld", &num);
		tmp = num;
		while (tmp != 0)
		{
			dig = tmp % 10;
			tmp = tmp / 10;
			if (dig != 0 && num%dig == 0)
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}

