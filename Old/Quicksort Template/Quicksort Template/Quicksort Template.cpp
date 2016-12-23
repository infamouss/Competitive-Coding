// Quicksort Template.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include "Array.h"
#include "Array.cpp"

using namespace std;


int main()
{
	int N;
	
	printf("Enter number of integers: ");
	scanf("%d", &N);
	Array<int> integer(N);
	integer.Scan();
	integer.QuickSort();
	printf("The sorted array is:\n");
	integer.Print();

	printf("Enter number of floats: ");
	scanf("%d", &N);
	Array<float> floating(N);
	floating.Scan();
	floating.QuickSort();
	printf("The sorted array is:\n");
	floating.Print();
	return 0;
}

