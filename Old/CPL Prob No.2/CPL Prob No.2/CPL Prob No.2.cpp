// CPL Prob No.2.cpp : Defines the entry point for the console application.
//

//header files declaration
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
//structure definition
typedef struct node_tag
{
	char data;
	int flag;
	struct node_tag * next;
}node_type;

typedef struct stack_tag
{
	node_type * top;
}stack_type;

typedef struct queue_tag
{
	node_type * front;
	node_type * rear;
}queue_type;


//function declaration
void initialize_stack(stack_type * stackptr);
node_type * make_node(char d);
int push(stack_type * stack_ptr, char d);
int pop(stack_type * stack_ptr, char * dptr);
int isempty(stack_type * stack_ptr);
void initialize_queue(queue_type *qptr);
int isemptyq(queue_type * qptr);
int insertqueue(queue_type * qptr, char d);
int deleteq(queue_type * qptr, char * dptr);
queue_type * change_format(char prefix_expression[]);
void print_q(queue_type *qptr);

//functions
void initialize_stack(stack_type * stackptr)
{
	stackptr->top = NULL;
}

node_type * make_node(char d)
{
	node_type * new_node;
	new_node = (node_type *)malloc(sizeof(node_type));
	if (new_node != NULL)
	{
		new_node->data = d;
		new_node->flag = 0;
		new_node->next = NULL;
	}
	return new_node;
}

int push(stack_type * stack_ptr, char d)
{
	int ret_val = 1;
	node_type * new_node;
	new_node = make_node(d);
	if (new_node != NULL)
	{
		new_node->next = stack_ptr->top;
		stack_ptr->top = new_node;
	}
	else
	{
		ret_val = 0;
	}
	return ret_val;
}//returns 1 if the contents are pushed onto the stack else 0

int pop(stack_type * stack_ptr, char * dptr)
{
	int ret_val = 1;
	node_type * node;
	if (stack_ptr->top == NULL)
	{
		ret_val = 0;
	}
	else
	{
		node = stack_ptr->top;
		*dptr = node->data;
		stack_ptr->top = node->next;
		free(node);
	}
	return ret_val;
}//returns 0 if pop is not successful else 1


int isempty(stack_type * stack_ptr)
{
	int ret_val = 0;
	if (stack_ptr->top == NULL)
	{
		ret_val = 1;
	}
	return ret_val;
}
//STACK ENDS HERE

//QUEUE STARTS HERE
void initialize_queue(queue_type *qptr)
{
	qptr->front = qptr->rear = NULL;
}

int isemptyq(queue_type * qptr)
{
	int ret_val;
	if (qptr->front == NULL)
	{
		ret_val = 1;
	}
	else
	{
		ret_val = 0;
	}
	return ret_val;
}

int insertqueue(queue_type * qptr, char d)
{
	int ret_val = 1;
	node_type * new_node;
	new_node = (node_type *)malloc(sizeof(node_type));
	new_node->data = d;
	new_node->next = NULL;
	if (isemptyq(qptr) == 1)
	{
		qptr->front = qptr->rear = new_node;
	}
	else
	{
		(qptr->rear)->next = new_node;
		qptr->rear = new_node;
	}
	return ret_val;
}

int deleteq(queue_type * qptr, char * dptr)
{
	int ret_val = 1;
	node_type * ptr;
	if (isemptyq(qptr) == 1)
	{
		ret_val = 0;
	}
	else
	{
		ptr = qptr->front;
		qptr->front = (qptr->front)->next;
		*dptr = ptr->data;
		free(ptr);
		if (qptr->front == NULL)
		{
			qptr->rear = NULL;
		}
	}
	return ret_val;
}

void print_q(queue_type *qptr)
{
	node_type *ptr = qptr->front;
	int n;
	char a;

	while (ptr != NULL)
	{
		printf("%c", ptr->data);
		ptr = ptr->next;

	}
	printf("\n");
}

//QUEUE ENDS HERE

queue_type * change_format(char prefix_expression[])
{
	stack_type *stack;
	queue_type *result_queue;
	stack = (stack_type *)malloc(sizeof(stack_type));
	result_queue = (queue_type *)malloc(sizeof(queue_type));
	int result, i, ret_val, flag;
	char temp;
	i = 0;
	ret_val = 1;
	initialize_stack(stack);
	initialize_queue(result_queue);
	while ((prefix_expression[i] != '\n') && (ret_val == 1))
	{
		if (isalnum(prefix_expression[i]))
		{
			if (!isempty(stack))
				result = insertqueue(result_queue, prefix_expression[i]);
			i++;
			if (stack->top != NULL)
			{
				stack->top->flag = stack->top->flag + 1;
				flag = 1;
				while (isempty(stack) != 1 && flag == 1)
				{
					if (stack->top->flag == 2)
					{
						result = pop(stack, &temp);
						result = insertqueue(result_queue, temp);
						if (stack->top != NULL)
						{
							stack->top->flag = stack->top->flag + 1;
						}
					}
					else
					{
						flag = 0;
					}
				}
			}
			else
			{
				ret_val = 0;
			}

		}
		else if (prefix_expression[i] == '+' || prefix_expression[i] == '-' || prefix_expression[i] == '*' || prefix_expression[i] == '/')
		{
			result = push(stack, prefix_expression[i]);
			i++;
		}
		else if (prefix_expression[i] == 32)
		{
			result = insertqueue(result_queue, prefix_expression[i]);
			i++;
		}
		else
		{
			ret_val = 0;
		}
	}
	return result_queue;
}

//main function starts here

int main()
{
	char prefix[20];
	char postfix[20], string[20];
	int result, i, count;
	node_type *ptr, *tmp;
	queue_type *out_put;
	FILE *fp, *fp1;
	fp = fopen("prefix.txt", "r");
	fp1 = fopen("postfix.txt", "w");
	while (fgets(string, sizeof(string), fp) != NULL)
	{
		count = strlen(string);
		strcpy(prefix, string);
		out_put = change_format(prefix);
		print_q(out_put);
		ptr = out_put->front;
		i = 0;
		while (ptr != NULL)
		{
			tmp = ptr;
			string[i] = ptr->data;
			ptr = ptr->next;
			free(tmp);
			i++;
		}
		i = i + 1;
		string[i] = '\0';
		if (count == i)
			fputs(string, fp1);
		else
			fputs("the expression is invalid\n", fp1);

	}
	return 0;
}
