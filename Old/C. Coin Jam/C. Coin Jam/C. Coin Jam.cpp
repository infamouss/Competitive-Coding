// C. Coin Jam.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int lastFactor;

bool isNotPrime(long long N)
{
	long long i = 2;
	bool retval = false;
	while (i*i <= N && !retval)
	{
		if (N%i == 0)
		{
			retval = true;
			lastFactor = i;
		}
		i++;
	}
	return retval;
}

void toBin(int N,char bin[])
{
	int i = 15;
	while (N > 0)
	{
		if (N % 2 == 1)
		{
			bin[i] = '1';
		}
		else
		{
			bin[i] = '0';
		}
		i--;
		N /= 2;
	}
	bin[16] = '\0';
}

long long toDec(char bin[], int base)
{
	long long ans = 0;
	long long mul = 1;

	for (int i = 15;i >= 0;i--)
	{
		if (bin[i] == '1')
		{
			ans += mul;
		}
		mul *= base;
	}
	return ans;
}


int count = 0;
int ans[50];
int factors[50][9];

bool isAcceptable(int n)
{
	bool retval = true;
	char bin[17];
	long long num;

	toBin(n, bin);

	for (int i = 2;(i <= 10) && retval;i++)
	{
		num = toDec(bin, i);
		retval = isNotPrime(num);
		if (retval)
		{
			factors[count][i - 2] = lastFactor;
		}
	}
	return retval;
}




int main()
{
	int i, N, J, T;
	FILE *inputFile, *outputFile;
	inputFile = fopen("C-small-attempt0.in", "r");
	outputFile = fopen("OUTPUT.txt", "w");
	fscanf(inputFile, "%d%d%d", &T, &N, &J);


	for (i = 32769;i <= 65535 && count < 50;i += 2)
	{
		if (isAcceptable(i))
		{
			ans[count] = i;
			count++;
		}
	}
	fprintf(outputFile, "Case #1:\n");
	for (i = 0;i < 50;i++)
	{
		//printf("%d", ans[i]);
		fprintf(outputFile, "%d", ans[i]);

		for (int j = 0;j < 9;j++)
		{
			//printf(" %d", factors[i][j]);
			fprintf(outputFile, " %d", factors[i][j]);
		}
		//printf("\n");
		fprintf(outputFile, "\n");
	}
	fclose(inputFile);
	fclose(outputFile);
	return 0;
}

