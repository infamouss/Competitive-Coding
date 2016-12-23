// GeneratingPrimes.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>

int main()
{
	unsigned long long i, j, count = 0;
	int flag;
	float limit;
	FILE* fp;
	fp = fopen("PRIMES.txt", "w");

	//for (i = 3; i <= 18446744073709551615; i += 3)
	//for (i = 3; i <= 10000000; i += 2)
	fprintf(fp, "%d,", 2);
	count++;
	for (i = 3; i <= 2000000; i += 2)
	{
		limit = sqrt((long double)i);
		flag = 0;
		j = 2;
		while (flag == 0 && j <= limit)
		{
			if (i % j == 0)
			{
				flag = 1;
			}
			j++;
		}

		if (flag == 0)
		{
			printf("%llu\n", i);
			fprintf(fp, "%llu,", i);
			//fprintf(fp, "%llu\n", i);
			count++;

		}




	}


	fclose(fp);




	return 0;
}

