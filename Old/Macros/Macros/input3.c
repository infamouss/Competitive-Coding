#include<stdio.h>
#define PI 3.145
#define square(z) (z*z)
#define area(z) (PI*square(z))

int main(){
int radius;
int area=6;
printf("enter the radius");
scanf("%d" , &radius);
area = area(radius);
printf("ar=%d" , area);
return 0;
}