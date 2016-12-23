// Maximizing XOR.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int a, b, max = 0, i, j, tmp;
	scanf("%d%d", &a, &b);
	for (i = a; i <= b; i++)
	{
		for (j = i; j <= b; j++)
		{
			tmp = i^j;
			if (tmp > max)
			{
				max = tmp;
				
			}
		}
	}
	printf("%d\n", max);
	return 0;
}

