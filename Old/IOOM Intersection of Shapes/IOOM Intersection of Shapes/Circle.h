#pragma once
#include "Shapes.h"
class Circle :
	public Shapes
{
private:
	int x, y, radius;
public:
	Circle(int X, int Y, int Rad);
	~Circle();
	virtual bool DoesIntersect(Shapes* C);
};

