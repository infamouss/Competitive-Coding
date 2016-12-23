#include<iostream>
using namespace std;
// Please write your code, within the "BEGIN-END" blocks given below.
// A "BEGIN-END" block is identified as follows :
//
// "//// BEGIN: Some string DONT_ERASE_xx_yy"
// 
//
// "//// END: Some other string DONT_ERASE_xx_yy"
//
// where "xx" is the block number and "yy" is the
// marks allocated for the block
//
// The FIRST block (BLOCK 1 i.e. DONT_ERASE_01_0) carries 0 marks and 
// is a placeholder for your personal information, to be written as a comment.
//
// WARNING :
// (1) Do NOT write any cout or cin statements
// (2) Do NOT delete or modify the existing code i.e. main function, comments, blocks, etc.
// (3) Write your code in between BEGIN and END of the respective blocks only
// (4) Do NOT rename the .cpp file

//// ---------------------------------------------------------------------------
//// BEGIN: Fill your details as comments below DONT_ERASE_01_0
//// Name:BALARAVEEN NADAR
////
//// END: Fill your details as comments above DONT_ERASE_01_0
//// ---------------------------------------------------------------------------

struct rational {
	int numerator;
	int denominator;
};

void reduce(struct rational *inputrational, struct rational *outputrational) {
	//// ---------------------------------------------------------------------------
	//// BEGIN: Write function code DONT_ERASE_02_1
	//// This function reduce is called by another function 'equal'.
	//// It should reduce the rational number to its lowest form


	int a = inputrational->numerator;
	int b = inputrational->denominator;
	int rem;
	do
	{
		rem = a%b;
		a = b;
		b = rem;
	} while (rem != 0);


	outputrational->numerator = inputrational->numerator / a;
	outputrational->denominator = inputrational->denominator / a;

	//// END: Function Code ends DONT_ERASE_02_1
	//// ---------------------------------------------------------------------------
}


bool equal(struct rational *rational_number1, struct rational *rational_number2) {
	//// ---------------------------------------------------------------------------
	//// BEGIN: Write function code DONT_ERASE_03_1
	//// This function 'equal' calls another function 'reduce' for both the numbers
	//// The function should return TRUE to the main function if,
	//// numerators of both the numbers are same and denominators of both the numbers are same,
	//// else it should return false


	bool retval = false;
	rational tmp1, tmp2;
	reduce(rational_number1, &tmp1);
	reduce(rational_number2, &tmp2);
	if (tmp1.numerator == tmp2.numerator && tmp1.denominator == tmp2.denominator)
	{
		retval = true;
	}

	return retval;
	//// END: Function code ends DONT_ERASE_03_1
	//// ---------------------------------------------------------------------------
}



int main() {
	int result;
	struct rational num1, num2;
	cout << "Enter Details of Number 1 " << endl;
	cout << "Enter Numerator :" << endl;
	cin >> num1.numerator;
	cout << "Enter Denominator :" << endl;
	cin >> num1.denominator;

	cout << "Enter Details of Number 2 " << endl;
	cout << "Enter Numerator :" << endl;
	cin >> num2.numerator;
	cout << "Enter Denominator :" << endl;
	cin >> num2.denominator;

	result = equal(&num1, &num2);
	if (result == true)
		cout << "Both rational numbers are equal" << endl;
	else
		cout << "Both rational numbers are not equal" << endl;
	return 0;
}
