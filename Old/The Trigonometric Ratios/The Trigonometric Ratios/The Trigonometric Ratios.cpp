// The Trigonometric Ratios.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	float x, s, c, ts, tc;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%f", &x);
		ts = s = x;
		tc = c = 1;
		
		//printf("%.3f\n%.3f\n", x - (x*x*x) / (float)(3 * 2) + (x*x*x*x*x) / (float)(5 * 4 * 3 * 2) - (x*x*x*x*x*x*x) / (float)(7 * 6 * 5 * 4 * 3 * 2) + (x*x*x*x*x*x*x*x*x) / (float)(9 * 8 * 7 * 6 * 5 * 4 * 3 * 2), 1 - x*x / (float)2 + (x*x*x*x) / (float)(4 * 3 * 2) - (x*x*x*x*x*x) / (float)(6 * 5 * 4 * 3 * 2) + (x*x*x*x*x*x*x*x) / (float)(8 * 7 * 6 * 5 * 4 * 3 * 2));
		//printf("%.3f\n%.3f\n", sin(x), cos(x));
		for (int i = 1;i < 5;i++)
		{
			ts *= -1 *x*x / (2 * i*(2 * i + 1));
			tc *= -1 *tc*x*x / (2 * i*(2 * i - 1));
			s += ts;
			c += tc;
		}
		printf("%3f\n%.3f\n", s, c);
	}


	return 0;
}