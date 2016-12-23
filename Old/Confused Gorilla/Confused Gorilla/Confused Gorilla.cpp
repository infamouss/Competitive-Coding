// Confused Gorilla.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	int N;
	int i, j;
	

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		

		for (i = 0; i <= N / 2; i++)
		{
			printf("%d %d\n", i, N - i);
			if (i != N - i)
				printf("%d %d\n", N - i, i);
		}



	}
	return 0;
}

