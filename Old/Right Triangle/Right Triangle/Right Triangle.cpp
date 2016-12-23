// Right Triangle.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/COOK71/problems/RIGHTTRI

#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	long T;
	double H, S, l1, l2;
	scanf("%ld", &T);
	while (T--)
	{
		scanf("%lf%lf", &H, &S);
		if (H*H < 4 * S)
		{
			printf("-1\n");
		}
		else
		{
			double theta = asin(4 * S / (H*H))/2.0;
			if (theta > atan(1))
			{
				l1 = H*cos(theta);
				l2 = H*sin(theta);
			}
			else
			{
				l2 = H*cos(theta);
				l1 = H*sin(theta);
			}
			printf("%f %f %f\n", l1, l2, H);
		}
	}
	return 0;
}

