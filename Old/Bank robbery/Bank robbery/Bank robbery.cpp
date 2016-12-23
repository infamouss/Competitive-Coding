// Bank robbery.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>


int main()
{
	long T, M;
	double p, cCash, fCash;
	scanf("%ld", &T);
	while (T--)
	{
		scanf("%ld%lf", &M, &p);
		if (p == 0)
		{
			cCash = 1000000000;
			fCash = 0;
		}
		else
		{
			
			if (M % 2 == 0)
			{
				fCash = 1000000000 * pow(p, M - 1);
				cCash = 1000000000 - fCash;
			}
			else
			{
				cCash = 1000000000 * pow(p, M - 1);
				fCash = 1000000000 - cCash;
			}
					
		}
		printf("%.2lf %.2lf\n", cCash, fCash);
	}



    return 0;
}

