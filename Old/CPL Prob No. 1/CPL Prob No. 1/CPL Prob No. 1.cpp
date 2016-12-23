// CPL Prob No. 1.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<stdlib.h>
typedef struct node_tag
{
	int element;
	struct node_tag *next;
}node;
typedef struct stack_tag
{
	node *top;
}stack;
void push(stack *sptr, int data)
{
	node *new_node;
	new_node = (node *)malloc(sizeof(node));
	new_node->element = data;
	new_node->next = sptr->top;
	sptr->top = new_node;
}
int pop(stack *sptr)
{
	node *obtain;
	int temp;
	obtain = sptr->top;
	sptr->top = obtain->next;
	temp = obtain->element;
	free(obtain);
	return temp;
}
int main()
{
	stack *sptr;
	sptr = (stack *)malloc(sizeof(stack));
	sptr->top = NULL;
	char entry[50], choice;
	int i = 0, var1, var2, ans, flag = 0, raise = 0, sum = 0;
	printf("Enter postfix expression:\n");
	scanf("%s", entry);
	while (entry[i] != '\0' && flag == 0)
	{
		if (entry[i] != '+' && entry[i] != '-' && entry[i] != '*' && entry[i] != '/')
		{
			sum = 0;
			while (entry[i] != ';' && entry[i] != '\0')
			{
				sum = sum * 10 + (int(entry[i] - 48));
				i++;
			}
			push(sptr, sum);
		}
		else
		{
			raise = 1;
			var1 = pop(sptr);
			if (sptr->top == NULL)
			{
				printf("Invalid Expression!\n");
				flag = 1;
			}
			else
			{
				var2 = pop(sptr);
				choice = entry[i];
				switch (choice)
				{
				case '+':
					ans = var1 + var2;
					push(sptr, ans);
					break;
				case '-':
					ans = var2 - var1;
					push(sptr, ans);
					break;
				case '*':
					ans = var1*var2;
					push(sptr, ans);
					break;
				case '/':
					ans = var2 / var1;
					push(sptr, ans);
					break;
				}
			}
		}
		i++;
	}
	if (flag == 0)
	{
		if ((sptr->top)->next != NULL || raise != 1)
		{
			printf("Invalid Expression!\n");
		}
		else
		{
			ans = pop(sptr);
			printf("The answer is %d\n", ans);
		}
	}
	return 0;

}
