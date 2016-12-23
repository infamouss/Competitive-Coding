#include "Rectangle.h"



Rectangle::Rectangle()
{
}

Rectangle::Rectangle(int X, int Y, int L, int B)
{
	x = X;
	y = Y;
	length = L;
	bredth = B;
}


Rectangle::~Rectangle()
{
}

bool Rectangle::DoesIntersect(Shapes* R)
{
	bool retval = true;
	Rectangle* r = (Rectangle*)R;
	int x1 = x, x2 = x + length, x3 = r->x, x4 = r->x + r->length;
	int y1 = y, y2 = y + bredth, y3 = r->y, y4 = r->y + r->bredth;





	
	retval = !((((x1 <= x3) && (x4 <= x2)) && ((y1 <= y3) && (y4 <= y2))) || (((x3 <= x1) && (x2 <= x4)) && ((y3 <= y1) && (y2 <= y4))));

	if (retval)
	{
		int dx = (x1 < x3) ? x3 - x1 : x1 - x3, dy = (y1 < y3) ? y3 - y1 : y1 - y3;
		//retval = ((dx < length) || (dx < r->length)) && ((dy < bredth) || (dy < r->bredth));
		retval = ((dx < length) && (dy < bredth)) || ((dx < r->length) && (dy < r->bredth));
	}

	return retval;
}
