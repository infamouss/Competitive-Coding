// [Algo] Matrix Rotation.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int M, R, N, i, j, k, levels, count;
	long arr[300][300], **linear;
	scanf("%d%d%d", &M, &N, &R);
	for (i = 0;i < M;i++)
	{
		for (j = 0;j < N;j++)
		{
			scanf("%ld", &arr[i][j]);
		}
	}
	
	levels = ((M < N) ? M : N) / 2;

	linear = (long**)malloc(sizeof(long*)*levels);

	



	return 0;
}

