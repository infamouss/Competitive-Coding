#include "Square.h"



Square::Square(int X, int Y, int S)
{
	x = X;
	y = Y;
	side = S;
}


Square::~Square()
{
}

bool Square::DoesIntersect(Shapes* Sq)
{
	bool retval = true;
	Square* sq = (Square*)Sq;
	int x1 = x, x2 = x + side, x3 = sq->x, x4 = sq->x + sq->side;
	int y1 = y, y2 = y + side, y3 = sq->y, y4 = sq->y + sq->side;


	retval = !((((x1 <= x3) && (x4 <= x2)) && ((y1 <= y3) && (y4 <= y2))) || (((x3 <= x1) && (x2 <= x4)) && ((y3 <= y1) && (y2 <= y4))));

	if (retval)
	{
		int dx = (x1 < x3) ? x3 - x1 : x1 - x3, dy = (y1 < y3) ? y3 - y1 : y1 - y3;
		//retval = ((dx < side) || (dx < sq->side)) && ((dy < side) || (dy < sq->side));
		retval = ((dx < side) && (dy < side)) || ((dx < sq->side) && (dy < sq->side));
	}

	return retval;
}
