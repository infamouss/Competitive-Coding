// Magical Field.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, M, N, xp, yp, xc, yc, dx, dy;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &M, &N);
		scanf("%d%d", &xp, &yp);
		scanf("%d%d", &xc, &yc);

		dx = (xp > xc) ? (xp - xc) : (xc - xp);
		dx = (N - dx < dx) ? (N - dx) : dx;
		dy = (yp > yc) ? (yp - yc) : (yc - yp);
		dy = (M - dy < dy) ? (M - dy) : dy;
		printf("%d\n", dx + dy);
	}
	return 0;
}

