// A very big sum.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

int main()
{
	int t;
	long tmp;
	long long sum = 0;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%ld", &tmp);
		sum += tmp;
	}
	printf("%lld", sum);



	return 0;
}

