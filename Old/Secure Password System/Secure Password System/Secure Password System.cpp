// Secure Password System.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	int m, M;
	scanf("%d", &T);
	while (T > 0)
	{
		scanf("%d%d", &m, &M);
		if (M > 6)
		{
			printf("YES\n");
		}
		else if (M == 6)
		{
			if (m < 6)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		else
		{
			printf("NO\n");
		}
		T--;
	}
	return 0;
}

