// Linked-List Palindrome.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>


typedef struct nodeTag
{
	int data;
	nodeTag* next;
} node;


node* createList(node*head, int data)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = head;
	return newNode;
}


node* isPalindrome(node* head, node* Head, bool* isPalin)
{
	node* tmp;
	if (head->next != NULL)
	{
		tmp = isPalindrome(head->next, Head, isPalin);
	}
	else
	{
		tmp = Head;
	}
	if (tmp->data != head->data)
	{
		*isPalin = false;
	}
	return tmp->next;
}



int main()
{
	int N, i, data;
	node *head = NULL, *tmp;
	bool isPalin = true;
	scanf("%d", &N);
	for (i = 0;i < N;i++)
	{
		scanf("%d", &data);
		head = createList(head, data);
	}
	tmp = isPalindrome(head, head, &isPalin);
	printf("%s", (isPalin) ? "YES" : "NO");
	return 0;
}