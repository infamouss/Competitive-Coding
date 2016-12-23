// The Smallest Pair.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	long T, N;
	int min, min2, tmp;
	scanf("%ld", &T);
	while (T--)
	{
		scanf("%ld", &N);
		N -= 2;
		scanf("%d%d", &min, &min2);
		if (min2 < min)
		{
			tmp = min2;
			min2 = min;
			min = tmp;
		}
		while (N--)
		{
			scanf("%d", &tmp);
			if (tmp < min)
			{
				min2 = min;
				min = tmp;
			}
			else if (tmp < min2)
			{
				min2 = tmp;
			}
		}
		printf("%d\n", min + min2);
	}
    return 0;
}

