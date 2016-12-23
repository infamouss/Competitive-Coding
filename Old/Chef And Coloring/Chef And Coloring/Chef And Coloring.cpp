// Chef And Coloring.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/APRIL16/problems/COLOR

#include <stdio.h>


int main()
{
	int T;
	long N, i, R, G, B, ans;
	char ip[100001];
	scanf("%d", &T);
	while (T--)
	{
		R = G = B = i = 0;
		scanf("%ld%s", &N, ip);
		while (ip[i]!='\0')
		{
			switch (ip[i])
			{
			case 'R':
				R++;
				break;
			case 'G':
				G++;
				break;
			case 'B':
				B++;
			}
			i++;
		}
		if (R >= B && R >= G)
			ans = N - R;
		else if (B >= R && B >= G)
			ans = N - B;
		else
			ans = N - G;
		printf("%ld\n", ans);
	}
	return 0;
}

