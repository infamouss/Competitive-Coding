#pragma once
class Shapes
{
public:
	Shapes();
	~Shapes();
	virtual bool DoesIntersect(Shapes *S);
};

