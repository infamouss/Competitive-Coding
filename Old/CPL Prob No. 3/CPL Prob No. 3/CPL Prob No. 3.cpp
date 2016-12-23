// CPL Prob No. 3.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


typedef struct node_tag
{
	char element;
	struct node_tag *next;
}node;
typedef struct stack_tag
{
	node *top;
}stack;
void push(stack *sptr, char data)
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
	char temp;
	obtain = sptr->top;
	sptr->top = obtain->next;
	temp = obtain->element;
	free(obtain);
	return temp;
}
int priority(char x)
{
	int ret_val;
	if (x == '+' || x == '-')
	{
		ret_val = 1;
	}
	else if (x == '*' || x == '/')
	{
		ret_val = 2;
	}
	return ret_val;
}
int main()
{
	stack *sptr;
	sptr = (stack *)malloc(sizeof(stack));
	sptr->top = NULL;
	char entry[15], temp, result[15], x;
	int i = 0, j = 0, k, flag = 0, flag_1 = 1,raise=0;
	printf("Enter infix expression:\n");
	gets(entry);
	k = strlen(entry);
	for (i = k; i>0; i--)
	{
		entry[i] = entry[i - 1];
	}
	entry[0] = '(';
	entry[k + 1] = ')';
	entry[k + 2] = '\0';
	for (i = 0, j = 0; entry[i] != '\0'; i++)
	{
		if (entry[i] != ' ')
		{
			result[j] = entry[i];
			j++;
		}
	}
	result[j] = '\0';
	strcpy(entry, result);
	j = 0;
	while (entry[i] != '\0' && flag_1 == 1)
	{
		temp = entry[i];
		if (temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '(' || temp == ')' || isdigit(temp) || isalpha(temp))
		{
			if (temp == '(')
			{
				push(sptr, temp);
			}
			else if (temp == ')')
			{
				if (sptr->top != NULL)
				{
					pop(sptr);
				}
				else
				{
					flag_1 = 0;
				}
			}
			i++;
		}
		else
		{
			flag_1 = 0;
		}
	}
	if (flag_1 == 1 && sptr->top != NULL)
	{
		flag_1 = 0;
	}
	if (flag_1 == 1)
	{
		i = 0;
		while (entry[i] != '\0')
		{
			temp = entry[i];
			if (temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '(' || temp == ')')
			{
				if (temp == '(')
				{
					push(sptr, temp);
				}
				else
				{
					if (temp == ')')
					{
						flag = 0;
						while ((sptr->top != NULL) && (flag == 0))
						{
							x = pop(sptr);
							if (x == '(')
							{
								flag = 1;
							}
							else
							{
								result[j] = x;
								j++;
							}
						}
					}
					else
					{
						if (sptr->top != NULL)
						{
							x = pop(sptr);
							while ((x != '(') && (priority(x) >= priority(temp)))
							{
								result[j] = x;
								j++;
								x = pop(sptr);
							}
							push(sptr, x);
							push(sptr, temp);
						}
						else
						{
							raise = 1;
						}
					}
				}
			}
			else
			{
				result[j] = temp;
				j++;
			}
			i++;
		}
		if (raise != 1)
		{
			result[j] = '\0';
			printf("Postfix expression is :%s.\n", result);
		}
		else
		{
			printf("Invalid Expression!\n");
		}
	}
	else
	{
		printf("Invalid Expression!\n");
	}
	return 0;
}
