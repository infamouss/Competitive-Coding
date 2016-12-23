#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define M_PI 3.14159265358979323846

typedef int(*compfn)(const void*, const void*);
typedef struct point {
	double x;
	double y;
	double r;
	double angle;
} Point;

int compare(struct point *elem1, struct point *elem2)
{
	//printf("Sorting...\n");
	if (elem1->angle < elem2->angle)
		return -1;

	else if (elem1->angle > elem2->angle)
		return 1;

	else {
		if (elem1->r < elem2->r)
			return -1;

		else if (elem1->r > elem2->r)
			return 1;

	}

	return 0;
}
int main() {
	int n;
	scanf("%d", &n);
	Point points[n];
	double x, y, angle;
	for (int i = 0; i < n; i++) {
		scanf("%lf", &x);
		scanf("%lf", &y);
		points[i].x = x;
		points[i].y = y;
		points[i].r = sqrt(pow(x, 2) + pow(y, 2));
		




		points[i].angle = atan2(points[i].y, points[i].x);










		if (x > 0 && y >= 0) //For quad 1
			while (points[i].angle < 0 || points[i].angle > M_PI / 2)
			{
				if (points[i].angle < 0)
					points[i].angle += M_PI;
				else
					points[i].angle -= M_PI;
			}
		if (x <= 0 && y > 0) //For quad 2
			while (points[i].angle < M_PI / 2 || points[i].angle > M_PI)
			{
				if (points[i].angle < M_PI / 2)
					points[i].angle += M_PI;
				else
					points[i].angle -= M_PI;
			}
		if (x < 0 && y <= 0) //For quad 3
			while (points[i].angle < M_PI || points[i].angle > 3 * M_PI / 2)
			{
				if (points[i].angle < M_PI)
					points[i].angle += M_PI;
				else
					points[i].angle -= M_PI;
			}
		if (x >= 0 && y < 0) //For quad 4
			while (points[i].angle < 3 * M_PI / 2 || points[i].angle > 2 * M_PI)
			{
				if (points[i].angle < 3 * M_PI / 2)
					points[i].angle += M_PI;
				else
					points[i].angle -= M_PI;
			}
		if (points[i].angle == -0 && x < 0) //Case for Negative X and Zero Y
			points[i].angle = M_PI;
		angle = points[i].angle;
		//printf("%lf\n", angle);
	}
	qsort((void *)&points, n, sizeof(Point), (compfn)compare);
	for (int i = 0; i < n; i++) {
		x = points[i].x;
		y = points[i].y;
		angle = points[i].angle;
		//printf("%lf ", angle);
		printf("%.0lf %.0lf\n", x, y);
	}

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	return 0;
}
