#include "TOH.h"
#include <iostream>

using namespace std;

TOH::TOH(int n)
{
	num = n;
}


TOH::~TOH()
{
}

void TOH::towers(int num, char source, char destination, char temp)
{
	if (num <= 0)
	{
		cout << "Number of Disk(s) is invalid..Nothing is Done!!\n";
	}
	else
	{
		if (num == 1)
		{
			cout << "\n Move disk 1 from peg " << source << " to peg " << destination;
			return;
		}
		towers(num - 1, source, temp, destination);
		cout << "\n Move disk " << num << " from peg " << source << " to peg " << destination;
		towers(num - 1, temp, destination, source);
	}
}
