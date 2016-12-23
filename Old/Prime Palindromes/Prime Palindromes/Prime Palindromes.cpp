// Prime Palindromes.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>

bool isPalindrome(long N)
{
	long num, rev = 0;
	bool retVal = false;
	num = N;
	while (num)
	{
		rev = rev * 10 + num % 10;
		num = num / 10;
	}
	if (rev == N)
	{
		retVal = true;
	}
	return retVal;
}

bool isPrime(long N)
{
	int sqr = sqrt(N);
	int i = 2;
	bool retVal = true;
	for (; i <= sqr && retVal; i++)
	{
		if (!(N%i))
			retVal = false;
	}
	return retVal;
}

int main()
{
	long N;
	bool done = false;
	scanf("%ld", &N);
	while (!done)
	{
		if (isPalindrome(N))
		{
			if (isPrime(N))
			{
				printf("%ld\n", N);
				done = true;
			}
		}
		++N;
	}
    return 0;
}

