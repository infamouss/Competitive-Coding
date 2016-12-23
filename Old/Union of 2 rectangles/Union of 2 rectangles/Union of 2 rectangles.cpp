// Union of 2 rectangles.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int x1, x2, y1, y2, l1, l2, w1, w2, x, y, l, w;
	scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &l1, &w1, &x2, &y2, &l2, &w2);
	x = (x1 < x2) ? x1 : x2;
	y = (y1 < y2) ? y1 : y2;
	l = (((x1 + l1) > (x2 + l2)) ? (x1 + l1) : (x2 + l2)) - x;
	w = (((y1 + w1) > (y2 + w2)) ? (y1 + w1) : (y2 + w2)) - y;
	printf("%d %d %d %d", x, y, l, w);
	return 0;
}

