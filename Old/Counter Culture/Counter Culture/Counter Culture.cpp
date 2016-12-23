// Counter Culture.cpp : Defines the entry point for the console application.
//

#include <stdio.h>




long long flip(long long n)
{
	long long ans = 0;
	while (n != 0)
	{
		ans = 10 * ans + n % 10;
		n = n / 10;
	}
	return ans;
}




















int main()
{
	long long T, i, num, count, tmp, tmp1;
	FILE *inputFile, *outputFile;
	inputFile = fopen("A-small-attempt1.in", "r");
	outputFile = fopen("OUTPUT.txt", "w");
	fscanf(inputFile, "%lld", &T);
	for (i = 1; i <= T; i++)
	{
		count = 0;
		tmp = 0;
		fscanf(inputFile, "%lld", &num);
		while (tmp != num)
		{
			tmp1 = flip(tmp);
			if (tmp1 > tmp&&tmp1 <= num)
			{
				tmp = tmp1;
			}
			else
			{
				tmp++;
			}
			count++;
		}


		fprintf(outputFile, "Case #%d: %lld\n", i, count);




	}






	return 0;
}

