// Special Numbers.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int primes[20] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71 };
	int T, i, j, k, arr[1140], n = 0;
	for (i = 0;i < 18;i++)
	{
		for (j = i + 1;j < 19;j++)
		{
			for (k = j + 1;k < 20;k++)
			{
				arr[n] = primes[i] * primes[j] * primes[k];
				n++;
			}
		}
	}
	
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		printf("%d\n", arr[n - 1]);
	}




	return 0;
}

