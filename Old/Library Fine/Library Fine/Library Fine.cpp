// Library Fine.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int dd, dm, dy, ad, am, ay;
	scanf("%d%d%d%d%d%d", &ad, &am, &ay, &dd, &dm, &dy);
	if (ay < dy)
	{
		printf("0");
	}
	else if (ay == dy)
	{
		if (am < dm)
		{
			printf("0");
		}
		else if (am == dm)
		{
			if (ad <= dd)
			{
				printf("0");
			}
			else
			{
				printf("%d", 15 * (ad - dd));
			}
		}
		else
		{
			printf("%d", 500 * (am - dm));
		}
	}
	else
	{
		printf("10000");
	}
	return 0;
}

