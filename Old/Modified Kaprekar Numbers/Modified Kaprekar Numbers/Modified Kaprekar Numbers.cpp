// Modified Kaprekar Numbers.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>


int length(long long num)
{
	int len = 0;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return len;
}




int main()
{
	long p, q;
	long long square, tmp;
	int len, flag = 0;

	scanf("%ld%ld", &p, &q);
	while (p <= q)
	{
		square = p*p;
		len = length(square);


		if (square / (long)pow(10, (len + 1) / 2) + square % (long)pow(10, (len + 1) / 2) == p)
		{
			printf("%ld ", p);
			flag = 1;
		}
			



		p++;
	}

	if (flag == 0)
		printf("INVALID RANGE");



	return 0;
}

