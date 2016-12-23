#include "stack.h"
#include <iostream>
using namespace std;


stack::stack(int size)
{
	if (size <= 0)
	{
		cout << "Stack size should be greater than zero!!!\n";
	}
	else
	{
		max_size = size;
		A = new int[size];
		top = -1;
	}
}

stack::~stack()
{
	delete A;
}

void stack::push(int element)
{
	if (isFull())
	{
		cout << "Stack Overflow!!!\n";
	}
	else
	{
		A[++top] = element;
		cout << "\nElement pushed\n";
	}
}

int stack::pop()
{
	if (isEmpty())
	{
		cout << "Error While Popping !!! Stack Empty!!!\n";
		return -1;
	}
	else
	{
		return A[top--];
	}
}

bool stack::isEmpty()
{
	return (top == -1);
}

bool stack::isFull()
{
	return (top == max_size - 1);
}

int stack::top_element()
{
	if (!isEmpty())
	{
		return A[top];
	}
	else
	{
		cout << "ERROR!! Top Unavailable!! Stack Empty!!!\n";
		return -1;
	}
}

void stack::print()
{
	for (int i = top; i >= 0; i--)
		cout << A[i] << " ";
	cout << "\n";
}
