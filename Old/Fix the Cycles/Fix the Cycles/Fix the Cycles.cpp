// Fix the Cycles.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

int Minimum(int a, int b, int c)
{
	int retval;
	if (a <= b && a <= c)
	{
		retval = a;
	}
	else if (b <= a && b <= c)
	{
		retval = b;
	}
	else
	{
		retval = c;
	}
	return retval;
}

int main()
{
	int a, b, c, d, e, f, min;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	min = Minimum(a + b + c + d, b + f + a, e + d + a);
	printf("%d", (min <= 0) ? min*(-1) : -1);





	return 0;
}

