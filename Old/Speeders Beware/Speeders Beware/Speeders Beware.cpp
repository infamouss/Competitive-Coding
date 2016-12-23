// Speeders Beware.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	float d, t, s;
	scanf("%f%f%f", &d, &t, &s);
	(d / t <= s*44.0 / 30.0)? printf("Not Speeding"): printf("Speeding");
	return 0;
}

