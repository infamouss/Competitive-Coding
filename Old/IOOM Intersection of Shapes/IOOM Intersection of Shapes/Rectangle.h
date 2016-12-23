#pragma once
#include "Shapes.h"
class Rectangle :
	public Shapes
{
protected:
	int x, y, length, bredth;
public:
	Rectangle();
	Rectangle(int X,int Y,int L,int B);
	~Rectangle();
	virtual bool DoesIntersect(Shapes* R);
};

