// Laddu.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/MAY16/problems/LADDU

#include <stdio.h>


int main()
{
	int T, N, ans, rank;
	char nat[11], activity[20];
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%d%s", &N, nat);
		while (N--)
		{
			scanf("%s", activity);
			switch (activity[8])
			{
			case 'W':
				scanf("%d", &rank);
				ans += (300 + ((rank < 20) ? (20 - rank) : 0));
				break;
			case 'R':
				ans += 300;
				break;
			case 'D':
				scanf("%d", &rank);
				ans += rank;
				break;
			case 'H':
				ans += 50;
			}
		}
		printf("%d\n", (nat[0] == 'I') ? ans / 200 : ans / 400);
	}
	return 0;
}

