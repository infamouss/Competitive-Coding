//						HEADER FILES

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//						TYPEDEF

typedef struct nodeTag
{
	char name[50], project[50], address[200], phone[11];
	float hours;
	nodeTag* next;
} node;
char x[2];



//						AUXILIARY FUNCTION DECLARATIONS


node* makeNode();
node* createList(node* lptr, int n);
node* copy(node *p);
void isEmpty(node* lptr);
void getNumRecords(node* lptr);
node* insert(node* lptr);
node* del(node* lptr);
void printList(node *lptr);
node* mergeSort(node* p);
node* merge(node* p, node* q);
node* divide(node* p);
void listUnique(node* p);
void getMaxNumHrs(node* lptr);
node* intersection(node* p, node* q);
node* listUnion(node* p, node* q);
node* difference(node* p, node* q);
node* symmetricDifference(node* p, node* q);
node* reset(node* lptr);





//						MAIN FUNCTION

int main()
{
	node *lptr = NULL, *listU = NULL, *listI = NULL, *listD = NULL, *listSd = NULL, *list1 = NULL, *list2 = NULL, *tmp = NULL;
	int command, n, commandL1, commandL2;
	FILE* fptr;
	printf("-1 for menu\n0 to exit\n1 to reset list\n2 to input from file\n3 to user input list\n4 for sorting\n");
	printf("5 for inserting\n6 for deleting\n7 for uniqueing\n8 for max num hrs\n9 for is empty\n10 for printing\n");
	printf("11 for L1 menu\n12 for L2 menu\n13 for union\n14 for intersection\n15 for diffrence\n16 for sym. difference\n");
	printf("17 to print union\n18 to print intersection\n19 to print difference\n20 to print sym. diffrence.\n");
	command = 1;
	while (command)
	{
		scanf("%d", &command);
		gets(x);
		switch (command)
		{
		case -1:									//MENU
			printf("-1 for menu\n0 to exit\n1 to reset list\n2 to input from file\n3 to user input list\n4 for sorting\n");
			printf("5 for inserting\n6 for deleting\n7 for uniqueing\n8 for max num hrs\n9 for is empty\n10 for printing\n");
			printf("11 for L1 menu\n12 for L2 menu\n13 for union\n14 for intersection\n15 for diffrence\n16 for sym. difference\n");
			printf("17 to print union\n18 to print intersection\n19 to print difference\n20 to print sym. diffrence.\n");
			break;
		case 0:										//EXIT
			printf("Thank you!\n");
			break;
		case 1:										//RESET LIST
			lptr = reset(lptr);
			printf("Reset successful!\n");
			break;
		case 2:										// INPUT FROM FILE
			lptr = reset(lptr);
			fptr = fopen("Input.txt", "r");
			while (!feof(fptr))
			{
				tmp = (node*)malloc(sizeof(node));
				fscanf(fptr, "%s%s%s%s%f", tmp->name, tmp->project, tmp->address, tmp->phone, &(tmp->hours));
				tmp->next = lptr;
				lptr = tmp;
			}
			printf("List read successfully!\n");
			fclose(fptr);
			lptr = mergeSort(lptr);
			break;
		case 3:										//CREATE LIST
			lptr = reset(lptr);
			printf("\nEnter number of enteries.\n");
			scanf("%d", &n);
			gets(x);
			lptr = createList(lptr, n);
			break;
		case 4:										//SORT
			lptr = mergeSort(lptr);
			break;
		case 5:										//INSERT
			lptr = insert(lptr);
			break;
		case 6:										//DELETE
			lptr = del(lptr);
			break;
		case 7:										//UNIQUE
			listUnique(lptr);
			break;
		case 8:										//MAX NUM HRS
			getMaxNumHrs(lptr);
			break;
		case 9:										//IS EMPTY
			isEmpty(lptr);
			break;
		case 10:									//PRINT LIST
			printList(lptr);
			break;
		case 11:									//LIST 1 MENU
			printf("-1 for menu\n0 for exit\n1 to reset L1\n2 input from file\n3 to user input\n4 for sorting\n");
			printf("5 to insert\n6 to delete\n7 to unique\n8 for max num hrs\n9 for is empty\n10 to print L1\n");
			commandL1 = 1;
			while (commandL1)
			{
				scanf("%d", &commandL1);
				gets(x);
				switch (commandL1)
				{
				case -1:				//MENU
					printf("-1 for menu\n0 for exit\n1 to reset L1\n2 input from file\n3 to user input\n4 for sorting\n");
					printf("5 to insert\n6 to delete\n7 to unique\n8 for max num hrs\n9 for is empty\n10 to print L1\n");
					break;
				case 0:					//EXIT
					printf("Exited from list 1 commands!\n");
					break;
				case 1:					//RESET LIST 1
					list1 = reset(list1);
					break;
				case 2:					//INPUT FROM FILE
					list1 = reset(list1);
					fptr = fopen("List1.txt", "r");
					while (!feof(fptr))
					{
						tmp = (node*)malloc(sizeof(node));
						fscanf(fptr, "%s%s%s%s%f", tmp->name, tmp->project, tmp->address, tmp->phone, &(tmp->hours));
						tmp->next = list1;
						list1 = tmp;
					}
					printf("List read successfully!\n");
					fclose(fptr);
					list1 = mergeSort(list1);
					break;
				case 3:					//CREATE LIST
					list1 = reset(list1);
					printf("Enter number of enteries.\n");
					scanf("%d", &n);
					gets(x);
					list1 = createList(list1, n);
					break;
				case 4:					//SORT
					list1 = mergeSort(list1);
					break;
				case 5:					//INSERT
					list1 = insert(list1);
					break;
				case 6:					//DELETE
					list1 = del(list1);
					break;
				case 7:					//UNIQUE
					listUnique(list1);
					break;
				case 8:					//MAX NUM HRS
					getMaxNumHrs(list1);
					break;
				case 9:					//IS EMPTY
					isEmpty(list1);
					break;
				case 10:				//PRINT LIST
					printList(list1);
					break;
				default:				//INVALID REQUEST
					printf("\nInvalid request!\n");
					break;
				}
			}
			break;
		case 12:									//LIST 2 MENU
			printf("-1 for menu\n0 for exit\n1 to reset L2\n2 input from file\n3 to user input\n4 for sorting\n");
			printf("5 to insert\n6 to delete\n7 to unique\n8 for max num hrs\n9 for is empty\n10 to print L2\n");
			commandL2 = 1;
			while (commandL2)
			{
				scanf("%d", &commandL2);
				gets(x);
				switch (commandL2)
				{
				case -1:				//MENU
					printf("-1 for menu\n0 for exit\n1 to reset L2\n2 input from file\n3 to user input\n4 for sorting\n");
					printf("5 to insert\n6 to delete\n7 to unique\n8 for max num hrs\n9 for is empty\n10 to print L2\n");
					break;
				case 0:					//EXIT
					printf("Exited from list 2 commands!\n");
					break;
				case 1:					//RESET LIST 2
					list1 = reset(list1);
					break;
				case 2:					//INPUT FROM FILE
					list2 = reset(list2);
					fptr = fopen("List2.txt", "r");
					while (!feof(fptr))
					{
						tmp = (node*)malloc(sizeof(node));
						fscanf(fptr, "%s%s%s%s%f", tmp->name, tmp->project, tmp->address, tmp->phone, &(tmp->hours));
						tmp->next = list2;
						list2 = tmp;
					}
					printf("List read successfully!\n");
					fclose(fptr);
					list2 = mergeSort(list2);
					break;
				case 3:					//CREATE LIST
					list2 = reset(list2);
					printf("Enter number of enteries.\n");
					scanf("%d", &n);
					gets(x);
					list2 = createList(list2, n);
					break;
				case 4:					//SORT
					list2 = mergeSort(list2);
					break;
				case 5:					//INSERT
					list2 = insert(list2);
					break;
				case 6:					//DELETE
					list2 = del(list2);
					break;
				case 7:					//UNIQUE
					listUnique(list2);
					break;
				case 8:					//MAX NUM HRS
					getMaxNumHrs(list2);
					break;
				case 9:					//IS EMPTY
					isEmpty(list2);
					break;
				case 10:				//PRINT LIST
					printList(list2);
					break;
				default:				//INVALID REQUEST
					printf("\nInvalid request!\n");
					break;
				}
			}
			break;
		case 13:									//UNION
			listU = listUnion(list1, list2);
			if (listU != NULL)
				printf("Operation succssful\n");
			break;
		case 14:									//INTERSECTION
			listI = intersection(list1, list2);
			if (listI != NULL)
				printf("Operation succssful\n");
			break;
		case 15:									//DIFFERENCE
			listD = difference(list1, list2);
			if (listD != NULL)
				printf("Operation succssful\n");
			break;
		case 16:									//SYMMETRIC DIFFERENCE
			listSd = symmetricDifference(list1, list2);
			if (listSd != NULL)
				printf("Operation succssful\n");
			break;
		case 17:									//PRINT UNION
			if (listU != NULL)
				printf("The list after union is:\n");
			printList(listU);
			break;
		case 18:									//PRINT INTERSECTION
			if (listI != NULL)
				printf("The list after intersection is:\n");
			printList(listI);
			break;
		case 19:									//PRINT DIFFERENCE
			if (listD != NULL)
				printf("The list after difference is:\n");
			printList(listD);
			break;
		case 20:									//PRINT SYMMETRIC DIFFERENCE
			if (listSd != NULL)
				printf("The list after symmetric difference is:\n");
			printList(listSd);
			break;
		default:									//INVALID REQUEST
			printf("\nInvalid request!\n");
			break;
		}
	}
	return 0;
}


//						makeNode FUNCTION DEFINATION

node* makeNode()
{
	node* newNode;
	printf("Enter employee name, project name, address, phone number, and hours\n");
	newNode = (node*)malloc(sizeof(node));
	gets(newNode->name);
	gets(newNode->project);
	gets(newNode->address);
	gets(newNode->phone);
	scanf("%f", &newNode->hours);
	gets(x);
	newNode->next = NULL;
	return newNode;
}


//						isEmpty FUNCTION DEFINATION

void isEmpty(node* lptr)
{
	if (lptr == NULL)
	{
		printf("List is empty!\n");
	}
	else
	{
		printf("List is not empty!\n");
	}
}


//						getNumRecords FUNCTION DEFINATION

void getNumRecords(node* lptr)
{
	int num;
	for (num = 0; lptr != NULL; lptr = lptr->next, num++);
	printf("Number of active records is %d.\n", num);
}


//						createList FUNCTION DEFINATION

node* createList(node* lptr, int n)
{
	node* newNode;
	int i;
	for (i = 0; i < n; i++)
	{
		newNode = (node*)malloc(sizeof(node));
		newNode->next = lptr;
		printf("Enter employee name, project name, address, plone number, and hours\n");
		gets(newNode->name);
		gets(newNode->project);
		gets(newNode->address);
		gets(newNode->phone);
		scanf("%f", &newNode->hours);
		gets(x);
		lptr = newNode;
	}
	lptr = mergeSort(lptr);
	printf("List created successfully!\n");
	return lptr;
}


//						insert FUNCTION DEFINATION

node* insert(node* lptr)
{
	node *prev, *newNode, *ptr;
	newNode = makeNode();
	prev = NULL;
	ptr = lptr;
	if (lptr == NULL)
	{
		lptr = newNode;
		printf("Entry added!\n");
	}
	else
	{
		while (ptr != NULL && strcmp(ptr->name, newNode->name)<0)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		if (ptr == NULL)
		{
			prev->next = newNode;
			printf("Entry added!\n");
		}
		else if (strcmp(ptr->name, newNode->name) == 0)
		{
			while (ptr != NULL && strcmp(ptr->project, newNode->project)<0 && strcmp(ptr->name, newNode->name) == 0)
			{
				prev = ptr;
				ptr = ptr->next;
			}
			if (ptr == NULL)
			{
				prev->next = newNode;
				printf("Entry added!\n");
			}
			else if (strcmp(ptr->project, newNode->project) == 0)
			{
				strcpy(ptr->address, newNode->address);
				strcpy(ptr->phone, newNode->phone);
				ptr->hours = newNode->hours;
				free(newNode);
				printf("Entry updated!\n");
			}
			else
			{
				if (prev == NULL)
				{
					newNode->next = ptr;
					lptr = newNode;
					ptr = lptr;
					printf("Entry added!\n");
				}
				else
				{
					prev->next = newNode;
					newNode->next = ptr;
					printf("Entry added!\n");
				}
			}
		}
		else
		{
			if (prev == NULL)
			{
				newNode->next = ptr;
				lptr = newNode;
				printf("Entry added!\n");
			}
			else
			{
				prev->next = newNode;
				newNode->next = ptr;
				printf("Entry added!\n");
			}
		}
		return lptr;
	}
}


//						del FUNCTION DEFINATION

node* del(node* lptr)
{
	char name[50], project[50];
	node *prev, *ptr;
	prev = NULL;
	ptr = lptr;
	printf("Enter employee name and project name\n");
	//gets(x);
	gets(name);
	gets(project);
	if (lptr == NULL)
	{
		printf("List is already empty!\n");
	}
	else
	{
		if (strcmp(ptr->name, name) == 0 && strcmp(ptr->project, project) == 0)
		{
			lptr = lptr->next;
			free(ptr);
			printf("Entry deleted!\n");
		}
		else
		{
			while (ptr != NULL && strcmp(ptr->name, name)<0)
			{
				prev = ptr;
				ptr = ptr->next;
			}
			if (ptr == NULL)
			{
				printf("Entry does not exist!\n");
			}
			else if (strcmp(ptr->name, name) == 0)
			{

				while (ptr != NULL && strcmp(ptr->project, project)<0 && strcmp(ptr->name, name) == 0)
				{
					prev = ptr;
					ptr = ptr->next;
				}
				if (ptr == NULL)
				{
					printf("Entry does not exist!\n");
				}
				else if (strcmp(ptr->project, project) == 0)
				{
					prev->next = ptr->next;
					free(ptr);
					printf("Entry deleted!\n");
				}
				else
				{
					printf("Entry does not exist!\n");
				}

			}
			else
			{
				printf("Entry does not exist!\n");
			}
		}
	}
	return lptr;
}


//						printList FUNCTION DEFINATION

void printList(node* lptr)
{
	if (lptr == NULL)
	{
		printf("List is empty!\n");
	}
	else
	{
		printf("%-20s\t%-20s\t%-20s\t%-12s\t%s\n", "Name", "Project", "Address", "Phone", "Hours");
		while (lptr != NULL)
		{
			printf("%-20s\t%-20s\t%-20s\t%-12s\t%.2f\n", lptr->name, lptr->project, lptr->address, lptr->phone, lptr->hours);
			lptr = lptr->next;
		}
	}

}


//						mergeSort	FUNCTION DEFINATION

node* mergeSort(node* p)
{
	node *q, *head;
	head = p;
	if (p != NULL&&p->next != NULL)
	{
		q = divide(p);
		p = mergeSort(p);
		q = mergeSort(q);
		head = merge(p, q);
	}
	return head;
}


//						merge FUNCTION DEFINATION

node* merge(node* p, node* q)
{
	node *head, *r;
	if (strcmp(p->name, q->name) == -1)
	{
		head = p;
		p = p->next;
	}
	else if (strcmp(p->name, q->name) == 0 && strcmp(p->project, q->project) <= 0)
	{
		head = p;
		p = p->next;
	}
	else
	{
		head = q;
		q = q->next;
	}
	r = head;
	while (p != NULL && q != NULL)
	{
		if (strcmp(p->name, q->name) == -1)
		{
			r->next = p;
			r = p;
			p = p->next;
		}
		else if (strcmp(p->name, q->name) == 0 && strcmp(p->project, q->project) <= 0)
		{
			r->next = p;
			r = p;
			p = p->next;
		}
		else
		{
			r->next = q;
			r = q;
			q = q->next;
		}
	}
	if (p != NULL)
	{
		r->next = p;
	}
	else
	{
		r->next = q;
	}
	return head;
}


//						divide FUNCTION DEFINATION

node* divide(node* p)
{
	node  *q, *r;
	q = p;
	r = p->next->next;
	while (r != NULL)
	{
		r = r->next;
		q = q->next;
		if (r != NULL)
		{
			r = r->next;
		}
	}
	r = q;
	q = q->next;
	r->next = NULL;
	return q;
}


//						listUnique FUNCTION DEFINATION

void listUnique(node* p)
{
	node *q, *r;
	if (p != NULL)
	{
		q = p;
		p = p->next;
		while (p != NULL)
		{
			if (strcmp(p->name, q->name) == 0 && strcmp(p->project, q->project) == 0)
			{
				r = p;
				p = p->next;
				q->next = p;
				free(r);
			}
			else
			{
				p = p->next;
				q = q->next;
			}
		}
		printf("Duplicate elements removed!\n");
	}
	else
	{
		printf("List is already empty!\n");
	}
}


//						getMaxNumHrs FUNCTION DEFINATION

void getMaxNumHrs(node* lptr)
{
	float hrs = 0;
	int count = 0;
	node* p;
	char project[50];
	printf("Enter project name.\n");
	gets(project);
	while (lptr != NULL)
	{
		if (strcmp(lptr->project, project) == 0)
		{
			if (lptr->hours > hrs)
			{
				hrs = lptr->hours;
				p = lptr;
				count = 1;
			}
			else if (lptr->hours == hrs)
				count++;
		}
		lptr = lptr->next;
	}
	if (count == 0)
	{
		printf("No employee(s) working in the project %s are.\n", project);
	}
	else
	{
		lptr = p;
		printf("List of employee(s) working in the project %s are for maximum time of %.2f hrs are:\n", project, hrs);
		while (count > 0)
		{
			if (strcmp(lptr->project, project) == 0 && lptr->hours == hrs)
			{
				printf("%s\n", lptr->name);
				count--;
			}
			lptr = lptr->next;
		}
	}
}


//						intresection FUNCTION DEFINATION

node* intersection(node* p, node* q)
{
	node *lptr, *ptr = NULL, *tail;
	if (p != NULL && q != NULL)
	{
		lptr = (node*)malloc(sizeof(node));
		tail = lptr;
		while (p != NULL && q != NULL)
		{
			if (strcmp(p->name, q->name) == -1)
			{
				p = p->next;
			}
			else if (strcmp(p->name, q->name) == 1)
			{
				q = q->next;
			}
			else
			{
				if (strcmp(p->project, q->project) == -1)
				{
					p = p->next;
				}
				else if (strcmp(p->project, q->project) == 1)
				{
					q = q->next;
				}
				else
				{
					ptr = copy(p);
					tail->next = ptr;
					tail = ptr;
					p = p->next;
					q = q->next;
				}
			}
		}
		ptr = lptr->next;
		free(lptr);
	}
	return ptr;
}


//						listUnion FUNCTION DEFINATION

node* listUnion(node* p, node* q)
{
	node *lptr, *tail, *ptr = NULL;
	lptr = (node*)malloc(sizeof(node));
	tail = lptr;
	if (p != NULL && q != NULL)
	{
		while (p != NULL && q != NULL)
		{
			if (strcmp(p->name, q->name) == -1)
			{
				ptr = copy(p);
				tail->next = ptr;
				tail = ptr;
				p = p->next;
			}
			else if (strcmp(p->name, q->name) == 1)
			{
				ptr = copy(q);
				tail->next = ptr;
				tail = ptr;
				q = q->next;
			}
			else
			{
				if (strcmp(p->project, q->project) == -1)
				{
					ptr = copy(p);
					tail->next = ptr;
					tail = ptr;
					p = p->next;
				}
				else if (strcmp(p->project, q->project) == 1)
				{
					ptr = copy(q);
					tail->next = ptr;
					tail = ptr;
					q = q->next;
				}
				else
				{
					ptr = copy(p);
					tail->next = ptr;
					tail = ptr;
					p = p->next;
					q = q->next;
				}
			}
		}
		if (p == NULL)
		{
			while (q != NULL)
			{
				ptr = copy(q);
				tail->next = ptr;
				tail = ptr;
				q = q->next;
			}
		}
		else
		{
			while (p != NULL)
			{
				ptr = copy(p);
				tail->next = ptr;
				tail = ptr;
				p = p->next;
			}
		}
	}
	else if (p == NULL)
	{
		while (q != NULL)
		{
			ptr = copy(q);
			tail->next = ptr;
			tail = ptr;
			q = q->next;
		}
	}
	else
	{
		while (p != NULL)
		{
			ptr = copy(p);
			tail->next = ptr;
			tail = ptr;
			p = p->next;
		}
	}
	ptr = lptr->next;
	free(lptr);
	return ptr;
}


//						copy FUNCTION DEFINATION

node* copy(node* p)
{
	node* newNode;
	newNode = (node*)malloc(sizeof(node));
	*newNode = *p;
	newNode->next = NULL;
	return newNode;
}


//						difference FUNCTION DEFINATION

node* difference(node* p, node* q)
{
	node *lptr, *tail, *ptr = NULL;
	if (p != NULL)
	{
		lptr = (node*)malloc(sizeof(node));
		tail = lptr;
		while (p != NULL && q != NULL)
		{
			if (strcmp(p->name, q->name) == -1)
			{
				ptr = copy(p);
				tail->next = ptr;
				tail = ptr;
				p = p->next;
			}
			else if (strcmp(p->name, q->name) == 1)
			{
				q = q->next;
			}
			else
			{
				if (strcmp(p->project, q->project) == -1)
				{
					ptr = copy(p);
					tail->next = ptr;
					tail = ptr;
					p = p->next;
				}
				else if (strcmp(p->project, q->project) == 1)
				{
					q = q->next;
				}
				else
				{
					p = p->next;
					q = q->next;
				}
			}
		}
		if (q == NULL)
		{
			while (p != NULL)
			{
				ptr = copy(p);
				tail->next = ptr;
				tail = ptr;
				p = p->next;
			}
		}
		ptr = lptr->next;
		free(lptr);
	}
	return ptr;
}


//						symmetricDifference FUNCTION DEFINATION

node* symmetricDifference(node* p, node* q)
{
	node *lptr, *tail, *ptr = NULL;
	if (p != NULL || q != NULL)
	{
		lptr = (node*)malloc(sizeof(node));
		tail = lptr;
		while (p != NULL && q != NULL)
		{
			if (strcmp(p->name, q->name) == -1)
			{
				ptr = copy(p);
				tail->next = ptr;
				tail = ptr;
				p = p->next;
			}
			else if (strcmp(p->name, q->name) == 1)
			{
				ptr = copy(q);
				tail->next = ptr;
				tail = ptr;
				q = q->next;
			}
			else
			{
				if (strcmp(p->project, q->project) == -1)
				{
					ptr = copy(p);
					tail->next = ptr;
					tail = ptr;
					p = p->next;
				}
				else if (strcmp(p->project, q->project) == 1)
				{
					ptr = copy(q);
					tail->next = ptr;
					tail = ptr;
					q = q->next;
				}
				else
				{
					p = p->next;
					q = q->next;
				}
			}
		}
		if (q == NULL)
		{
			while (p != NULL)
			{
				ptr = copy(p);
				tail->next = ptr;
				tail = ptr;
				p = p->next;
			}
		}
		else if (p == NULL)
		{
			while (q != NULL)
			{
				ptr = copy(q);
				tail->next = ptr;
				tail = ptr;
				q = q->next;
			}
		}
		ptr = lptr->next;
		free(lptr);
	}
	return ptr;
}


//						reset FUNCTION DEFINATION

node* reset(node* lptr)
{
	node* tmp;
	while (lptr != NULL)
	{
		tmp = lptr;
		lptr = lptr->next;
		free(tmp);
	}
	return lptr;
}