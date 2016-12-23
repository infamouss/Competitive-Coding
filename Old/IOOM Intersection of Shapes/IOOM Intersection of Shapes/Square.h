#pragma once
#include "Rectangle.h"
class Square :
	public Rectangle
{
private:
	int side;
public:
	Square(int X,int Y,int S);
	~Square();
	virtual bool DoesIntersect(Shapes* Sq);
};

