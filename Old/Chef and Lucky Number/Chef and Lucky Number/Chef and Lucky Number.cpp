// Chef and Lucky Number.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>


int main()
{
	int T, flag, j, limit;
	long N;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld", &N);
		limit = sqrt((long double)N);
		flag = 0;
		j = 2;
		while (flag == 0 && j <= limit)
		{
			if (N % j == 0)
			{
				flag = 1;
			}
			j++;
		}
		if (flag == 0)
		{
			printf("LUCKY NUMBER\n");
		}
		else
		{
			printf("Sorry\n");
		}
	}
    return 0;
}

