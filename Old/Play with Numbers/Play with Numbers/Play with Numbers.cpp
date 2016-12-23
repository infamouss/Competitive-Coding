// Play with Numbers.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	long long N, X, Y, i, count, Z;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld%lld", &Z, &X, &Y);
		count = 0;
		for (i = 1;i <= Z&&i <= X;i++)
		{
			if (Z%i == 0)
			{
				if (Z / i <= Y)
				{
					count++;
				}
			}
		}
		printf("%lld\n", count);
	}
	return 0;
}

