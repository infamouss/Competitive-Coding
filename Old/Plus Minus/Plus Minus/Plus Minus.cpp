// Plus Minus.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	float n, p = 0, ne = 0, z = 0;
	int tmp;
	scanf("%f", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", &tmp);
		if (tmp < 0)
		{
			ne++;
		}
		else if (tmp > 0)
		{
			p++;
		}
		else
		{
			z++;
		}
	}
	printf("%f\n%f\n%f",  p / n, ne / n, z / n);


	return 0;
}

