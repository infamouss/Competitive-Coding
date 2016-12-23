// Fibonacci Modified.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	long double t3, t2, t1;
	int n, i;

	scanf("%d%Lf%Lf", &n, &t1, &t2);
	printf("%.0Lf %.0Lf", t1, t2);
	for (i = 0; i < n; i++)
	{
		t3 = t2*t2 + t1;
		t1 = t2;
		t2 = t3;
	}

	printf("%.0Lf", t3);





	return 0;
}

