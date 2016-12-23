// Chef and cakes.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	long N, K;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld%ld", &N, &K);
		
		if (N % (K + 1) == 0 || N % (N - K + 1) == 0)
		{
			//no
		}
		else
		{
			if (N%K == 0)
			{
				//yes
			}
			else
			{

			}
		}




	}




	return 0;
}

