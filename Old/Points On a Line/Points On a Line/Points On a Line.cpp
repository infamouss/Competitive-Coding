// Points On a Line.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/101hack38/challenges/points-on-a-line

#include <stdio.h>


int main()
{
	int N, fx, fy, cx, cy, nx, ny, sum = 0;
	scanf("%d", &N);
	N--;
	scanf("%d%d", &fx, &fy);
	cx = fx;
	cy = fy;
	while (N--)
	{
		scanf("%d%d", &nx, &ny);
		sum += cx*ny - cy*nx;
		cx = nx;
		cy = ny;
	}
	sum += cx*fy - cy*fx;
	printf("%s\n", (sum == 0) && ((cx - fx == 0) || (fy - cy == 0)) ? "YES" : "NO");
	return 0;
}

