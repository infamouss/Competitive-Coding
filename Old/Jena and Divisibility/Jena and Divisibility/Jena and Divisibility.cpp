// Jena and Divisibility.cpp : Defines the entry point for the console application.
// url:https://www.hackerrank.com/contests/holi-code/challenges/jena-and-divisibility

#include <stdio.h>


int main()
{
	int T, k, value;
	long i, ans;
	char ip[1000001];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s%d", ip, &k);
		ans = i = 0;
		value = 0;
		while (ip[i] != '\0')
		{
			if (ip[i] == '0')
				value = value * 2 + 0;
			else
				value = value * 2 + 1;
			if (value%k == 0)
				ans++;
			value %= k;
			i++;
		}
		printf("%ld\n", ans);
	}
	return 0;
}

