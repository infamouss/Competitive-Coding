#include "Circle.h"



Circle::Circle(int X, int Y, int Rad)
{
	x = X;
	y = Y;
	radius = Rad;
}


Circle::~Circle()
{
}

bool Circle::DoesIntersect(Shapes* C)
{
	bool retval = false;
	Circle* c = (Circle*)C;
	if (radius > 0 && c->radius > 0)
	{
		int dist = (x - c->x)*(x - c->x) + (y - c->y)*(y - c->y);
		
		retval = ((radius - c->radius)*(radius - c->radius) < dist) && (dist < (c->radius + radius)*(c->radius + radius));
	}
	return retval;
}
