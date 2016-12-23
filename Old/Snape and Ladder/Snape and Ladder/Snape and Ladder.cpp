// Snape and Ladder.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>


int main()
{
	int T;
	float b, ls;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%f%f", &b, &ls);
		printf("%f %f\n", sqrt(ls*ls - b*b), sqrt(ls*ls + b*b));
	}
    return 0;
}

