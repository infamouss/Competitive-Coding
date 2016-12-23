// TOH using Classes.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include <cmath>
#include "TOH.h"

using namespace std;


int main()
{
	int N;
	cout << "Enter the number of disks : ";
	cin >> N;
	TOH tow(N);
	cout << "The sequence of moves involved in the Tower of Hanoi are :\n";
	tow.towers(tow.num, 'A', 'C', 'B');
	cout << "\nThe Number Of steps Required Are:" << pow(2, tow.num) - 1;
	return 0;
}

