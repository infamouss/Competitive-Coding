#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct nodeTag
{
	int data;
	nodeTag* next;
} node;


typedef struct stackTag
{
	node* top;
} stack;

void push(stack* stck, int data);
void pop(stack* stck, int* dapr);
node* makeNode(int data);

int main()
{
	int ans,num,p,q,i=0;
	char a[100];
	stack *stck;
	stck = (stack*)malloc(sizeof(stack));
	stck->top = NULL;
	scanf("%s", a);
	while (a[i] != '\0')
	{
		num = (int)a[i] - (int)'0';
		if (num >= 0 && num <= 9)
		{
			push(stck,num);
		}
		else
		{
			switch (a[i])
			{
			case '+':
				pop(stck, &p);
				pop(stck, &q);
				ans = q + p;
				push(stck, ans);
				break;
			case '-':
			
				pop(stck, &p);
				pop(stck, &q);
				ans = q - p;
				push(stck, ans);
				break;
			case '*':
				pop(stck, &p);
				pop(stck, &q);
				ans = q*p;
				push(stck, ans);
				break;
			case '/':
				pop(stck, &p);
				pop(stck, &q);
				ans = q / p;
				push(stck, ans);
				break;
			}
		}
		
		i++;
	}
	i = 0;
	pop(stck, &ans);
	printf("%d", ans);
	return 0;
}



void push(stack* stck, int data)
{
	node* newNode;
	newNode = makeNode(data);
	newNode->next = stck->top;
	stck->top = newNode;
}


void pop(stack* stck, int* dptr)
{
	node* tmp;
	tmp = stck->top;
	*dptr = tmp->data;
	stck->top = tmp->next;
	free(tmp);
}



node* makeNode(int d)
{
	node* newNode;
	newNode = (node*)malloc(sizeof(node));
	newNode->data = d;
	return newNode;
}