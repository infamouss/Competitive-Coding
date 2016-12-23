// TOH.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<math.h>
using namespace std;


void towers(int num, char source, char destination, char temp)
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


int main()
{
	int num;
	cout << "Enter the number of disks : ";
	cin >> num;
	if (num < 1)
	{
		cout << "Please enter valid a number\n";
	}
	else
	{
		cout << "The sequence of moves involved in the Tower of Hanoi are :\n";
		towers(num, 'A', 'C', 'B');
		cout << "\nThe Number Of steps Required Are:" << pow(2, num) - 1 << endl;
	}
	return 0;
}

