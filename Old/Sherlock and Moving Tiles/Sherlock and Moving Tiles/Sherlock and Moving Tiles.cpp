// Sherlock and Moving Tiles.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>


int main()
{
	long double L, S1, S2, V, query;
	long Q;
	scanf("%Lf%Lf%Lf", &L, &S1, &S2);
	V = (S1 < S2) ? S2 - S1 : S1 - S2;
	scanf("%ld", &Q);
	while (Q--)
	{
		scanf("%Lf", &query);
		printf("%Lf\n", sqrtl(2) * (L - sqrtl(query)) / V);
	}
	return 0;
}

