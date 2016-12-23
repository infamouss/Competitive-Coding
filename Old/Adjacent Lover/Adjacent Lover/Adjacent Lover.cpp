// Adjacent Lover.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/holi-code/challenges/adjacent-lover

#include <stdio.h>


int main()
{
	int T;
	long i, lastCoupleIndex;
	long long ans;
	char ip[1000001];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", ip);
		ans = 0;
		if (ip[1] != '\0')
		{
			i = 1;
			lastCoupleIndex = 0;
			while (ip[i] != '\0')
			{
				if (ip[i] == ip[i - 1])
				{
					ans -= (i - lastCoupleIndex + 1)*(i - lastCoupleIndex) / 2;
					lastCoupleIndex = i;
				}
				i++;
			}
			ans -= (i - lastCoupleIndex + 1)*(i - lastCoupleIndex) / 2;
			ans += i*(i + 1) / 2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

