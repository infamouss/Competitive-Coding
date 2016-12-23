// D. Fractiles.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


long long power(int a, int b)
{
	long long ans = 1, mul = a;

	while (b != 0)
	{
		if (b % 2 == 1)
		{
			ans *= mul;
		}
		mul *= mul;
		b /= 2;
	}
	return ans;
}

int main()
{
	int T, i, K, C, S, j;
	FILE *inputFile, *outputFile;
	//inputFile = fopen("D-small-attempt0.in", "r");
	//outputFile = fopen("OUTPUT.txt", "w");
	
	scanf("%d", &T);
	//fscanf(inputFile, "%d", &T);
	for (i = 1;i <= T;i++)
	{
		scanf("%d%d%d", &K, &C, &S);
		//fscanf(inputFile, "%d%d%d", &K, &C, &S);

		if (C == 1)
		{

			if (S == 1)
			{
				if (K == 1)
				{
					printf("Case #%d: 1\n", i);
					//fprintf(outputFile, "Case #%d: 1\n", i);
				}
				else
				{
					printf("Case #%d: IMPOSSIBLE\n", i);
					//fprintf(outputFile, "Case #%d: IMPOSSIBLE\n", i);
				}
			}
			else if (S < K)
			{
				printf("Case #%d: IMPOSSIBLE\n", i);
				//fprintf(outputFile, "Case #%d: IMPOSSIBLE\n", i);
			}
			else
			{
				printf("Case #%d:", i);
				//fprintf(outputFile, "Case #%d:", i);
				for (j = 1;j <= K;j++)
				{
					printf(" %d", j);
					//fprintf(outputFile, " %d", j);
				}
				printf("\n");
				//fprintf(outputFile, "\n");
			}
		}
		else	//C>1
		{

			if (S == 1)
			{
				if (K == 1)
				{
					printf("Case #%d: 1\n", i);
					//fprintf(outputFile, "Case #%d: 1\n", i);
				}
				else if (K == 2)
				{
					printf("Case #%d: 2\n", i);
					//fprintf(outputFile, "Case #%d: 2\n", i);
				}
				else
				{
					printf("Case #%d: IMPOSSIBLE\n", i);
					//fprintf(outputFile, "Case #%d: IMPOSSIBLE\n", i);
				}
			}
			else
			{
				if (K == 1)
				{
					printf("Case #%d: 1\n", i);
					//fprintf(outputFile, "Case #%d: 1\n", i);
				}
				else if (K == 2)
				{
					printf("Case #%d: 2\n", i);
					//fprintf(outputFile, "Case #%d: 2\n", i);
				}
				else
				{
					printf("Case #%d: 2 %lld\n", i, power(K, C) - 1);
					//fprintf(outputFile, "Case #%d: 2 %lld\n", i, power(K, C) - 1);
				}
			}
		}
	}
	fclose(inputFile);
	fclose(outputFile);
	return 0;
}

