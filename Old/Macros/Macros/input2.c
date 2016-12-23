#include <stdio.h>
#include <conio.h>
#define ADD(x,y) x+y
#define MULT(x,y) x*y
#define AREA(R) PI*R*R
#define R 5
#define IF(x,y,z) x?y:z
#define PI 3.1424
int main()
{
int num=ADD(MULT(3,4),ADD(MULT(5,2),1));
int area=AREA(R);
int val=IF(TRUE,4,5);
return 0;
}