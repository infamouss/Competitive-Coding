// Chef and Dolls.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, type[100000] = { 0 };
	long N, tmp, ans, i;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld", &N);
		ans = 0;
		while (N--)
		{
			scanf("%ld", &tmp);
			type[tmp] = (type[tmp] + 1) % 2;
		}
		
		for (i = 0;i < 100000;i++)
		{
			if (type[i] == 1)
			{
				printf("%ld\n", i);
				type[i] = 0;
				i = 100000;
			}
		}
	}
    return 0;
}

