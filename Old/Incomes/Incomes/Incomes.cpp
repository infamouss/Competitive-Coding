// Incomes.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>





int main()
{
	long int N, Q, i;
	long int S, X;
	unsigned long int* cumArr[4];


	cumArr[0] = (unsigned long int*)malloc(sizeof(unsigned long int) * 250000000);
	cumArr[1] = (unsigned long int*)malloc(sizeof(unsigned long int) * 250000000);
	cumArr[2] = (unsigned long int*)malloc(sizeof(unsigned long int) * 250000000);
	cumArr[3] = (unsigned long int*)malloc(sizeof(unsigned long int) * 250000001);


	for (i = 0;i < 250000000;i++)
	{
		cumArr[0][i] = 0;
		cumArr[1][i] = 0;
		cumArr[2][i] = 0;
		cumArr[3][i] = 0;
	}
	cumArr[3][i] = 0;



	scanf("%ld", &N);
	for (i = 0;i < N;i++)
	{
		scanf("%ld", &S);
		cumArr[S]++;
	}

	for (i = 1;i < 250000001;i++)
	{
		cumArr[i] = cumArr[i] + cumArr[i - 1];
	}




	scanf("%ld", &Q);
	while (Q--)
	{
		scanf("%ld", &X);
		


		printf("%ld\n", cumArr[X]);
	}




	return 0;
}

