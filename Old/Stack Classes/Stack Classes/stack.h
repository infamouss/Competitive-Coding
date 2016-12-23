//#pragma once
class stack
{
private:
	int max_size;
	int top;
	int *A;
public:
	stack(int);
	~stack();
	void push(int);
	int pop();
	bool isEmpty();
	bool isFull();
	int top_element();
	void print();
};

