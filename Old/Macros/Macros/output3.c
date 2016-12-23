#include<stdio.h>

int main(){
int radius;
int area=6;
printf("enter the radius");
scanf("%d" , &radius);
area = (3.145*(radius*radius));
printf("ar=%d" , area);
return 0;
}