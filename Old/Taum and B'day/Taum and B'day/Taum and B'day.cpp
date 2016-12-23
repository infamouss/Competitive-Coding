// Taum and B'day.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	long B, W, X, Y, Z;
	long long cost;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld%ld%ld%ld%ld", &B, &W, &X, &Y, &Z);
		cost = 0;
		if (X + Z < Y)//white
		{
			cost += W*(X + Z);
		}
		else
		{
			cost += W*Y;
		}
		if (Y + Z < X)//black
		{
			cost += B*(Y + Z);
		}
		else
		{
			cost += B*X;
		}
		printf("%lld\n", cost);
	}
	return 0;
}

