//						HEADER FILES

#include<stdio.h>
#include<string.h>


//						#DEFINE

#define SIZE 500


//						GLOBAL VARIABLAE DECLARATION

struct Project
{
	char NAME[50], PROJECT[50], ADDRESS[200], PHONE[11];
	float HOURS;
	int SALARY;
} RECORD[SIZE], TMP, new_record, RECORD1[SIZE / 2], RECORD2[SIZE / 2];
int N = 0, N1 = 0, N2 = 0;
char x[2];



//						AUXILIARY FUNCTION DECLARATIONS

void menu();
void reset(struct Project record[], int n);
void input(struct Project record[], int n);
void insert(struct Project TMP, int min, int max);
void sort(struct Project record[], int n);
void del(char name[], char project[], int min, int max);
void active();
void empty();
void full();
int unique(struct Project record[], int n);
void output(struct Project record[], int n);
void list_union();
void list_intersection();
void list_difference();
void symmetric_difference();
int search(struct Project record[], char name[], char project[], int min, int max);
void max_num_hrs(char project[]);


//						MAIN FUNCTION

int main()
{
	int n, command = 1, command1 = 1, assist;
	char name[50], project[50];
	reset(RECORD, SIZE);
	reset(RECORD1, SIZE / 2);
	reset(RECORD2, SIZE / 2);
	menu();
	while (command)
	{
		scanf("%d", &command);
		gets(x);
		switch (command)
		{
		case 0:					//EXIT
		{
			printf("THANK YOU.\n");
			break;
		}
		case 1:					//MENU
		{
			menu();
			break;
		}
		case 2:					//RESET
		{
			reset(RECORD, SIZE);
			printf("Successfully reseted!\n");
			break;
		}
		case 3:					//OUTPUT
		{
			output(RECORD, N);
			break;
		}
		case 4:					//INPUT
		{
			reset(RECORD, SIZE);
			printf("Enter number of entries.\n");
			scanf("%d", &N);
			gets(x);
			input(RECORD, N);
			sort(RECORD, N);
			printf("Successfully inputs are taken!\n");
			break;
		}
		case 5:					//SORT
		{
			sort(RECORD, N);
			printf("Successfully sorted!\n");
			break;
		}
		case 6:					//SRARCH
		{
			assist = -1;
			printf("Enter name of employee and project name.\n");
			gets(name);
			gets(project);
			assist = search(RECORD, name, project, 0, N);
			if (assist == -1)
			{
				printf("Entry not found.\n");
			}
			else
			{
				printf("Entry found.\n");
				printf("%s\t", RECORD[assist].NAME);
				printf("%s\t", RECORD[assist].PROJECT);
				printf("%s\t", RECORD[assist].ADDRESS);
				printf("%s\t", RECORD[assist].PHONE);
				printf("%.2f\t", RECORD[assist].HOURS);
				printf("%d\n", RECORD[assist].SALARY);
			}
			break;
		}
		case 7:					//DELETE
		{
			printf("Enter name of employee and project name.\n");
			gets(name);
			gets(project);
			del(name, project, 0, N);
			break;
		}
		case 8:					//INSERT
		{
			printf("Enter name of employee, project name, address, phone no, working hours and salary.\n");
			gets(new_record.NAME);
			gets(new_record.PROJECT);
			gets(new_record.ADDRESS);
			gets(new_record.PHONE);
			scanf("%f", &new_record.HOURS);
			gets(x);
			scanf("%d", &new_record.SALARY);
			gets(x);
			insert(new_record, 0, N);
			break;
		}
		case 9:					//ACTIVE RECORDS
		{
			active();
			break;
		}
		case 10:				//FULL OR NOT
		{
			full();
			break;
		}
		case 11:				//EMPTY OR NOT
		{
			empty();
			break;
		}
		case 12:				//UNIQUE
		{
			N = unique(RECORD, N);
			printf("Duplicate elements removed.\n");
			break;
		}
		case 13:				//MAXIMUM NUM RECORDS
		{
			printf("Enter name of project.\n");
			gets(project);
			max_num_hrs(project);
			break;
		}
		case 14:				//MULTI-LIST OPERATIONS
		{
			command1 = 1;
			printf("Press 0 to exit list command menu.\nPress 1 to again display the menu.\nPress 2 to reset list1.\n");
			printf("Press 3 to reset list2.\nPress 4 to input list1.\nPress 5 to input list2.\n");
			printf("Press 6 for list union.\nPress 7 for list intersection.\nPress 8 for list difference.\n");
			printf("Press 9 for list symmetric difference.\nPress 10 to output the list.\n");
			while (command1)
			{
				scanf("%d", &command1);
				gets(x);
				switch (command1)
				{
				case 0:			//EXIT
				{
					printf("List command exited.\n");
					break;
				}
				case 1:			//MENU
				{
					printf("Press 0 to exit list command menu.\nPress 1 to again display the menu.\nPress 2 to reset list1.\n");
					printf("Press 3 to reset list2.\nPress 4 to input list1.\nPress 5 to input list2.\n");
					printf("Press 6 for list union.\nPress 7 for list intersection.\nPress 8 for list difference.\n");
					printf("Press 9 for list symmetric difference.\nPress 10 to output the list.\n");
					break;
				}
				case 2:			//RESET FIRST LIST
				{
					reset(RECORD1, SIZE / 2);
					printf("List one successfully reseted.\n");
					break;
				}
				case 3:			//RESET SECOND LIST
				{
					reset(RECORD2, SIZE / 2);
					printf("List two successfully reseted.\n");
					break;
				}
				case 4:			//INPUT LIST ONE
				{
					printf("Enter number of entries.\n");
					scanf("%d", &N1);
					gets(x);
					reset(RECORD1, SIZE / 2);
					input(RECORD1, N1);
					sort(RECORD1, N1);
					break;
				}
				case 5:			//INPUT LIST TWO
				{
					printf("Enter number of entries.\n");
					scanf("%d", &N2);
					gets(x);
					reset(RECORD2, SIZE / 2);
					input(RECORD2, N2);
					sort(RECORD2, N2);
					break;
				}
				case 6:			//LIST UNION
				{
					reset(RECORD, SIZE);
					list_union();
					printf("List united.\n");
					break;
				}
				case 7:			//LIST INTERSECTON
				{
					reset(RECORD, SIZE);
					list_intersection();
					printf("List intersected.\n");
					break;
				}
				case 8:			//LIST DIFFERENCE
				{
					reset(RECORD, SIZE);
					list_difference();
					printf("List differentiated.\n");
					break;
				}
				case 9:			//LIST SYMMETRIC DIFFERENCE
				{
					reset(RECORD, SIZE);
					symmetric_difference();
					break;
				}
				case 10:		//OUTPUT 
				{
					output(RECORD, N);
					break;
				}
				default:
				{
					printf("BAD REQUEST!\n");
					break;
				}
				}
			}
			break;
		}
		default:
		{
			printf("BAD REQUEST!\n");
			break;
		}
		}
	}
	return 0;
}


//						MENU FUNCTIN DEFINATION

void menu()
{
	printf("Press 0 to exit.\nPress 1 to again display the menu.\nPress 2 to reset the list.\n");
	printf("Press 3 to output the list.\nPress 4 to enter data in list.\nPress 5 to sort the list.\n");
	printf("Press 6 to search an entry.\nPress 7 to delete an entry.\nPress 8 to insert an entry.\n");
	printf("Press 9 to know no. of active records.\nPress 10 to know if the list is full or not.\nPress 11 to know if the list is empty or not.\n");
	printf("Press 12 to remove duplicate elements.\nPress 13 to to print maximum time spent by employees in a project.\nPress 14 for list operations.\n");
}


//						RESET FUNCTION DEFINATION

void reset(struct Project record[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		record[i].NAME[0] = '~';
		record[i].PROJECT[0] = '~';
		record[i].ADDRESS[0] = '~';
		record[i].PHONE[0] = '~';
		record[i].HOURS = 0;
		record[i].SALARY = 0;
	}
}


//						INPUT FUNCTION DEFINATION

void input(struct Project record[], int n)
{
	int i;
	printf("Enter employee's name, project name, address, phone no, working hours and salary respectively.\n");
	for (i = 0; i < n;)
	{
		gets(record[i].NAME);
		gets(record[i].PROJECT);
		gets(record[i].ADDRESS);
		gets(record[i].PHONE);
		scanf("%f", &record[i].HOURS);
		gets(x);
		scanf("%d", &record[i].SALARY);
		gets(x);
		i++;
		if (i < n)
		{
			printf("Enter next entry.\n");
		}
	}
}


//						SORT FUNCTION DEFINATION

void sort(struct Project record[], int n)
{
	int i, j, cond;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			cond = strcmp(record[i].NAME, record[j].NAME);
			if (cond == 1)
			{
				TMP = record[i];
				record[i] = record[j];
				record[j] = TMP;
			}
		}
	}
}


//						DELETE FUNCTION DEFINATION

void del(char name[], char project[], int min, int max)
{
	int mid;
	mid = (min + max) / 2;
	if ((strcmp(name, RECORD[mid].NAME) == 0))
	{
		RECORD[mid].NAME[0] = '~';
		RECORD[mid].PROJECT[0] = '~';
		RECORD[mid].ADDRESS[0] = '~';
		RECORD[mid].PHONE[0] = '~';
		RECORD[mid].HOURS = 0;
		RECORD[mid].SALARY = 0;
		sort(RECORD, N);
		N--;
		printf("Delete successful!\n");
	}
	else if (max == min || max - min == 1)
	{
		printf("Entry not found!\n");
	}
	else if (strcmp(name, RECORD[mid].NAME) == -1)
	{
		max = mid;
		del(name, project, min, max);
	}
	else if (strcmp(name, RECORD[mid].NAME) == 1)
	{
		min = mid;
		del(name, project, min, max);
	}
}


//						ACTIVE FUNCTION DEFINATION

void active()
{
	printf("Number of active records is %d.\n", N);
}


//						EMPTY FUNCTION DEFINATION

void empty()
{
	if (N == 0)
	{
		printf("List is empty!\n");
	}
	else
	{
		printf("List is not empty!\n");
	}
}


//						FULL FUNCTION DEFINATION

void full()
{
	if (N == SIZE)
	{
		printf("List is full!\n");
	}
	else
	{
		printf("List is not full!\n");
	}
}


//						INSERT FUNCTION DEFINATION

void insert(struct Project new_record, int min, int max)
{
	int mid, i;
	mid = (min + max) / 2;
	if ((strcmp(new_record.NAME, RECORD[mid].NAME) == 0))
	{
		RECORD[mid] = new_record;
		printf("Entry updated!\n");
	}
	else if (max == min || max - min == 1)
	{
		if (N == SIZE)
		{
			printf("No place to insert!\n");
		}
		else
		{
			i = N;
			RECORD[N] = new_record;
			N++;
			while (strcmp(RECORD[i - 1].NAME, RECORD[i].NAME) > 0)
			{
				TMP = RECORD[i - 1];
				RECORD[i - 1] = RECORD[i];
				RECORD[i] = TMP;
				i--;
			}
		}
	}
	else if (strcmp(new_record.NAME, RECORD[mid].NAME) == -1)
	{
		max = mid;
		insert(new_record, min, max);
	}
	else if (strcmp(new_record.NAME, RECORD[mid].NAME) == 1)
	{
		min = mid;
		insert(new_record, min, max);
	}
}


//						OUTPUT FUNCTION DEFINATION

void output(struct Project record[], int n)
{
	int i;
	for (i = 0; (record[i].NAME[0] != '~') && (i < SIZE); i++)
	{
		printf("%s\t", record[i].NAME);
		printf("%s\t", record[i].PROJECT);
		printf("%s\t", record[i].ADDRESS);
		printf("%s\t", record[i].PHONE);
		printf("%.2f\t", record[i].HOURS);
		printf("%d\n", record[i].SALARY);
	}
}


//						SEARCH FUNCTION DEFINATION

int search(struct Project record[], char name[], char project[], int min, int max)
{
	int mid;
	mid = (min + max) / 2;
	if ((strcmp(name, record[mid].NAME) == 0))
	{
		return (mid);
	}
	else if (max == min || max - min == 1)
	{
		return (-1);
	}
	else if (strcmp(name, record[mid].NAME) == -1)
	{
		max = mid;
		search(record, name, project, min, max);
	}
	else if (strcmp(name, record[mid].NAME) == 1)
	{
		min = mid;
		search(record, name, project, min, max);
	}
}


//						UNIQUE FUNCTUION DEFINATION

int unique(struct Project record[], int n)
{
	int i = 1, j = 0;
	while (record[i].NAME[0] != '~')
	{
		if (strcmp(record[j].NAME, record[i].NAME) != 0)
		{
			j++;
			if (i != j)
			{
				record[j] = record[i];
			}
		}
		i++;
	}
	j++;
	n = j;
	for (; j < i; j++)
	{
		record[j].NAME[0] = '~';
		record[j].PROJECT[0] = '~';
		record[j].ADDRESS[0] = '~';
		record[j].PHONE[0] = '~';
		record[j].HOURS = 0;
		record[j].SALARY = 0;
	}
	return (n);
}


//						MAX NUN HRS FUNCTION DEFINATION

void max_num_hrs(char project[])
{
	int i = 0, j = 0;
	float max_hrs = 0;
	for (; (i < N) && (RECORD[i].NAME[0] != '~'); i++)
	{
		if (!strcmp(project, RECORD[i].PROJECT))
		{
			if (max_hrs < RECORD[i].HOURS)
			{
				max_hrs = RECORD[i].HOURS;
			}
		}
	}
	if (max_hrs == 0)
	{
		printf("No employee currently working in the given project\n");
	}
	else
	{
		printf("Highest hours spent by any employ in %s is %.2f.\nEmploys spending maximum hours are:\n", project, max_hrs);
		for (; j < i; j++)
		{
			if (!strcmp(project, RECORD[j].PROJECT))
			{
				if (max_hrs == RECORD[j].HOURS)
				{
					printf("%s\n", RECORD[j].NAME);
				}
			}
		}
	}
}


//						LIST UNION FUNCTION DEFINATION

void list_union()
{
	int i = 0, j = 0, k = 0, dec;
	reset(RECORD, SIZE);
	while ((RECORD1[i].NAME[0] != '~') || (RECORD2[j].NAME[0] != '~'))
	{
		dec = strcmp(RECORD1[i].NAME, RECORD2[j].NAME);
		if (dec == 0)
		{
			if (RECORD1[i].HOURS <= RECORD2[j].HOURS)
			{
				RECORD[k] = RECORD1[i];
			}
			else
			{
				RECORD[k] = RECORD2[j];
			}
			i++;
			j++;
			k++;
		}
		else if (dec == -1)
		{

			RECORD[k] = RECORD1[i];
			i++;
			k++;
		}
		else if (dec == 1)
		{
			RECORD[k] = RECORD2[j];
			j++;
			k++;
		}
	}
	N = k;
}


//						LIST INTERSECTION FUNCTION DEFINATION

void list_intersection()
{
	int i = 0, j = 0, k = 0, found = 0;
	N1 = unique(RECORD1, N1);
	N2 = unique(RECORD2, N2);
	while (i < N1 && j < N2)
	{
		if (strcmp(RECORD1[i].NAME, RECORD2[j].NAME) < 0)
			i++;
		else if (strcmp(RECORD1[i].NAME, RECORD2[j].NAME) > 0)
			j++;
		else
		{
			if (RECORD1[i].HOURS < RECORD2[j].HOURS)
			{
				RECORD[k] = RECORD1[i];
			}
			else
			{
				RECORD[k] = RECORD2[j];
			}
			i++;
			j++;
			k++;
		}
	}
	N = k;
}


//						LIST DIFFERENCE FUNCTION DEFINATION

void list_difference()
{
	int assist, i, k = 0;
	for (i = 0; i < N1; i++)
	{
		assist = search(RECORD2, RECORD1[i].NAME, RECORD1[i].PROJECT, 0, N2);
		if (assist == -1)
		{
			RECORD[k] = RECORD1[i];
			k++;
		}
	}
	N = k;
}


//							LIST SYMMETRIC DIFFERENCE FUNCTION DEFINATION

void symmetric_difference()
{
	int assist, i, k = 0;
	for (i = 0; i < N1; i++)
	{
		assist = search(RECORD2, RECORD1[i].NAME, RECORD1[i].PROJECT, 0, N2);
		if (assist == -1)
		{
			RECORD[k] = RECORD1[i];
			k++;
		}
	}
	for (i = 0; i < N2; i++)
	{
		assist = search(RECORD1, RECORD2[i].NAME, RECORD2[i].PROJECT, 0, N1);
		if (assist == -1)
		{
			RECORD[k] = RECORD2[i];
			k++;
		}
	}
	N = k;
	sort(RECORD, N);
}