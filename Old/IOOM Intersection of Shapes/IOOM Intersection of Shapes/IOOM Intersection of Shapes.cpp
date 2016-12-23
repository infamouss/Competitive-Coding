// IOOM Intersection of Shapes.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include "Shapes.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"



bool DoesIntersect(Shapes* S1, Shapes* S2)
{
	
	return S1->DoesIntersect(S2);
	

}



int main()
{
	int w, x, y, z;
	Shapes *S1, *S2;
	bool ans;



	printf("Enter coordinates and radius of first circle\n");
	scanf("%d%d%d", &x, &y, &z);
	Circle c1(x, y, z);
	printf("Enter coordinates and radius of second circle\n");
	scanf("%d%d%d", &x, &y, &z);
	Circle c2(x, y, z);
	
	


	printf("Enter coordinates of lower left vertex of first rectangle and its length and bredth\n");
	scanf("%d%d%d%d", &w, &x, &y, &z);
	Rectangle r1(w, x, y, z);
	printf("Enter coordinates of lower left vertex of second rectangle and its length and bredth\n");
	scanf("%d%d%d%d", &w, &x, &y, &z);
	Rectangle r2(w, x, y, z);



	printf("Enter coordinates of lower left vertex of first square and its side\n");
	scanf("%d%d%d", &x, &y, &z);
	Square sq1(x, y, z);
	printf("Enter coordinates of lower left vertex of second square and its side\n");
	scanf("%d%d%d", &x, &y, &z);
	Square sq2(x, y, z);

	S1 = &c1;
	S2 = &c2;
	ans = DoesIntersect(S1, S2);

	printf("The given circles %sintersect.\n", (ans) ? "" : "do not ");

	S1 = &r1;
	S2 = &r2;
	ans = DoesIntersect(S1, S2);

	printf("The given rectangles %sintersect.\n", (ans) ? "" : "do not ");

	S1 = &sq1;
	S2 = &sq2;
	ans = DoesIntersect(S1, S2);

	printf("The given squares %sintersect.\n", (ans) ? "" : "do not ");





	return 0;
}

