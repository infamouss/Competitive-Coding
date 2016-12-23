// Chef-Detective.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	long N, i, arr[100001] = { 0 }, tmp;
	scanf("%ld", &N);

	for (i = 1;i <= N;i++)
	{
		scanf("%d", &tmp);
		arr[tmp]++;
	}

	for (i = 1;i <= N;i++)
	{
		if (arr[i] == 0)
		{
			printf("%d ", i);
		}
	}



	return 0;
}

