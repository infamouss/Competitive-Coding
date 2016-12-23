// C. Fashion Police.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

bool debug = false;

int main()
{
	FILE *inputFile, *outputFile;
	if (!debug)
	{
		inputFile = fopen("C-small-practice (1).in", "r");
		outputFile = fopen("OUTPUT.txt", "w");
	}


	int T, i, j, k, l, m, J, P, S, K, JP, SP, PS;



	if (!debug)
	{
		fscanf(inputFile, "%d", &T);
	}
	else
	{
		scanf("%d", &T);
	}

	for (i = 1;i <= T;i++)
	{

		if (!debug)
		{
			fscanf(inputFile, "%d%d%d%d", &J, &P, &S, &K);
		}
		else
		{
			scanf("%d%d%d%d", &J, &P, &S, &K);
		}

		int out[10][10][10] = { 0 };



		

		for (j = 0;j < J;j++)
		{
			for (k = 0;k < P;k++)
			{
				JP = 0;
				for (l = 0;l < S;l++)
				{
					if (JP >= K)
					{
						out[j][k][l] = 1;
					}
					if(out[j][k][l] == 0)
						JP++;
				}
			}
		}

		
		for (j = 0;j < P;j++)
		{
			for (k = 0;k < S;k++)
			{
				PS = 0;
				for (l = 0;l < J;l++)
				{
					if (PS >= K)
					{
						out[l][j][k] = 1;
					}
					if(out[l][j][k] == 0)
						PS++;
				}
			}
		}


		for (j = 0;j < S;j++)
		{
			for (k = 0;k < P;k++)
			{
				SP = 0;
				for (l = 0;l < J;l++)
				{
					if (SP >= K)
					{
						out[l][k][j] = 1;
					}
					if(out[l][k][j] == 0)
						SP++;
				}
			}
		}

		int ans = 0;
		for (j = 0;j < J;j++)
		{
			for (k = 0;k < P;k++)
			{
				for (l = 0;l < S;l++)
				{
					if (out[j][k][l] == 0)
						ans++;
				}
			}
		}

		if (!debug)
		{
			fprintf(outputFile, "Case #%d: %d\n", i, ans);
			for (j = 0;j < J;j++)
			{
				for (k = 0;k < P;k++)
				{
					for (l = 0;l < S;l++)
					{
						if (out[j][k][l] == 0)
							fprintf(outputFile, "%d %d %d\n", j+1, k+1, l+1);
					}
				}
			}
		}
		else
		{
			printf("Case #%d: %d\n", i, ans);
			for (j = 0;j < J;j++)
			{
				for (k = 0;k < P;k++)
				{
					for (l = 0;l < S;l++)
					{
						if (out[j][k][l] == 0)
							printf("%d %d %d\n", j+1, k+1, l+1);
					}
				}
			}
		}


	}






	if (!debug)
	{
		fclose(inputFile);
		fclose(outputFile);
	}
	return 0;
}

