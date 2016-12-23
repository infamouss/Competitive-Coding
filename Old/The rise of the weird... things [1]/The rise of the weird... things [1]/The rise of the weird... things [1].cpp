// The rise of the weird... things [1].cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int N, count[1001] = { 0 }, tmp, i, j;
	long vTotal = 0, zTotal = 0;
	scanf("%d", &N);
	for (i = 0;i < N;i++)
	{
		scanf("%d", &tmp);
		count[tmp]++;
		if (tmp % 2 == 0)
		{
			zTotal += tmp;
		}
		else
		{
			vTotal += tmp;
		}
	}

	for (i = 0;i < 1001;i+=2)
	{
		for (j = 0;j < count[i]; j++)
		{
			printf("%d ", i);
		}
	}
	printf("%ld ", zTotal);
	for (i = 1;i < 1001;i += 2)
	{
		for (j = 0;j < count[i]; j++)
		{
			printf("%d ", i);
		}
	}
	printf("%ld ", vTotal);

	return 0;
}

