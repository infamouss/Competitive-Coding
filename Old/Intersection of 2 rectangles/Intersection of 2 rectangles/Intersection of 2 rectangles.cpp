// Intersection of 2 rectangles.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>


int cmpfunc(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}


int main()
{
	int x[4], y[4], l1, l2, w1, w2, i, j;
	scanf("%d%d%d%d%d%d%d%d", &x[0], &y[0], &l1, &w1, &x[1], &y[1], &l2, &w2);
	x[2] = x[0] + l1;
	x[3] = x[1] + l2;
	y[2] = y[0] + w1;
	y[3] = y[1] + w2;
	qsort(x, 4, sizeof(int), cmpfunc);
	qsort(y, 4, sizeof(int), cmpfunc);
	printf("%d %d %d %d", x[1], y[1], x[2]-x[1], y[2]-y[1]);
	return 0;
}