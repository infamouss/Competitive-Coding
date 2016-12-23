// Gunja Don.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int n, i;
	long long ans = 0, multiplier = 1;
	char ip[51];
	scanf("%d%s", &n, ip);
	for (i = 0;i < n;i++)
	{
		if (ip[i] == '0' || ip[i] == '5')
		{
			ans += multiplier;
		}
		multiplier *= 2;
	}
	printf("%lld\n", ans % 1000000007);
    return 0;
}

