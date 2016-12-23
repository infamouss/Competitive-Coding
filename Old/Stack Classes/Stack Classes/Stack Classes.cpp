#include <iostream>
#include "stack.h"
using namespace std;
int main()
{
	int stack_size, ch, t;
	//char c;
	cout << "Enter the stack size: ";
	cin >> stack_size;
	stack stk(stack_size);
	do								//menu
	{
		cout << "\n1. PUSH\n";		//Push an element 
		cout << "2. POP\n";			//Pop an element
		cout << "3. TOP\n";			//Display Top
		cout << "4. IsEMPTY\n";		//Returns true if stack is empty
		cout << "5. IsFULL\n";		//Returns true if stack is full
		cout << "6. Print\n";		//Print the elements on stack
		cout << "7. EXIT\n";		//Exit
		cout << "\nPlease Enter the Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1: cout << "Enter the element: ";
			cin >> t;
			stk.push(t);
			break;
		case 2: cout << stk.pop();
			break;
		case 3: cout << stk.top_element() << endl;
			break;
		case 4: if (stk.isEmpty())
			cout << "\tYES The Stack Is Empty\n";
				else
					cout << "\tNO, the Stack Contains Some Data\n";
			break;
		case 5: if (stk.isFull())
			cout << "\tYES The Stack Is Full\n";
				else
					cout << "\tNO We Can ADD more elemnts to the Stack\n";
			break;
		case 6: stk.print();
			break;
		case 7: exit(0);
		default:cout << "INVALID choice...\n";
		}
	} while (true);
	return 0;
}
