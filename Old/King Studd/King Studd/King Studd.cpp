// King Studd.cpp : Defines the entry point for the console application.
//url:https://www.codechef.com/ASNE2016/problems/STUDD

#include <stdio.h>
#include <string.h>


int main()
{
	int T, cost[26], i, j, len;
	long ans;
	char ip[100001];
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%s", ip);
		for (i = 0;i < 26;i++)
		{
			scanf("%d", &cost[i]);
		}
		j = strlen(ip) - 1;
		i = 0;
		while (i < j)
		{
			if (ip[i] != ip[j])
			{
				ans += cost[ip[i] - 'a']>cost[ip[j] - 'a'] ? cost[ip[j] - 'a'] : cost[ip[i] - 'a'];
			}
			i++;
			j--;
		}

		printf("%ld\n", ans);

	}
	return 0;
}

