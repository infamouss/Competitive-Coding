// Xor-sequence.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int Q;
	long long xoredL, xoredR;
	scanf("%d", &Q);
	for (int a0 = 0; a0 < Q; a0++)
	{
		long long L;
		long long R;
		scanf("%lld %lld", &L, &R);

		L = L - 1;
		//R = R + 1;

		if (L % 2 == 1)
		{
			xoredL = (L % 4 == 1) ? 1 : 0;
		}
		else
		{
			xoredL = (L % 4 == 0) ? L : L + 1;
		}

		if (R % 2 == 1)
		{
			xoredR = (R % 4 == 1) ? 1 : 0;
		}
		else
		{
			xoredR = (R % 4 == 0) ? R : R + 1;
		}




		printf("%lld\n", xoredR^xoredL);

	}





	return 0;
}

