/* Author : Your Name  */
/* Email  : Your Email */


/* System Includes */
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* Local Includes */
#include "JEEadvRanking.h"

/* External function prototypes */

/* Local #defines */

/* Local function prototypes */
int readInput();
int meritList();



typedef struct list
{
	long roll;
	int marks[3];
	int total;
	int index;
}ranklist;




char generateNum(char a[], long* num);

void mergeSortMod(list arr[], int l, int r, int min, int smin);
void mergedata(list arr[], int l, int m, int r, int min, int smin);

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);




/* Local Globals */
/* THE FOLLOWING IS A SIMPLE IMPLEMENTATION, PROBABLY NOT IDEAL */
/* DEFINE YOUR OWN STRUCTURES TO HOLD INPUT DATA */
/* Initial Size of arrays, arrays will need to be extended for large input */
#define MAXSTUDENTS	(500000)
static int validStudents;     /* Number of valid student data read */
long rollNumber[MAXSTUDENTS]; /* Roll Numbers of Valid Students */
int  physics[MAXSTUDENTS];    /* Physics Marks of Valid Students */
int  chemistry[MAXSTUDENTS];  /* Chemistry Marks of Valid Students */
int  mathematics[MAXSTUDENTS];/* Mathematics Marks of Valid Students */
long meritRank[MAXSTUDENTS];  /* Ranking of students (indices into rollNumber Array) */







ranklist student[MAXSTUDENTS];
//int total[MAXSTUDENTS];




int readInput()
{
	int lineNumber;               /* Line number of input record */
	static char *currentLine;     /* For accessing current line */
	char status;
	long tmp, tmpRoll;
	int i = 0;
	int j = 0;
	char aa[100];
	int tmpP = 0, tmpC = 0, tmpM = 0;



	validStudents = 0;
	lineNumber = 1;
	currentLine = readInputLine();



	while ((currentLine != NULL) && (validStudents < MAXSTUDENTS))
	{

		
		i = j = tmpP = tmpC = tmpM = 0;


		while (currentLine[i] != ',' && currentLine != '\0')
		{
			aa[j] = currentLine[i];
			i++;
			j++;
		}
		aa[j] = '\0';
		
		status = generateNum(aa, &tmp);
		tmpRoll = tmp;

		if (status == 'f' || status == 'F')
		{
			printError(INVROLLNO, lineNumber);
			
		}
		else if (tmpRoll < 1000000 || tmpRoll >= 10000000)
		{
			printError(ROLLRANGE, lineNumber);
			
		}
		else
		{
			i++;
			j = 0;
			while (currentLine[i] != ',' && currentLine != '\0')
			{
				aa[j] = currentLine[i];
				i++;
				j++;
			}
			aa[j] = '\0';
			
			status = generateNum(aa, &tmp);
			tmpP = (int)tmp;

			if (status == 'f' || status == 'F')
			{
				printError(INVMARKS, lineNumber);
				
			}
			else if (tmpP < -40 || tmpP > 160)
			{
				printError(MARKSRANGE, lineNumber);
				
			}
			else
			{
				i++;
				j = 0;
				while (currentLine[i] != ',' && currentLine != '\0')
				{
					aa[j] = currentLine[i];
					i++;
					j++;
				}
				aa[j] = '\0';
				
				status = generateNum(aa, &tmp);
				tmpC = (int)tmp;

				if (status == 'f')
				{
					printError(INVMARKS, lineNumber);
					
				}
				else if (tmpC < -40 || tmpC > 160)
				{
					printError(MARKSRANGE, lineNumber);
					
				}
				else
				{
					i++;
					j = 0;
					while (currentLine[i] != '\0')
					{
						aa[j] = currentLine[i];
						i++;
						j++;
					}
					aa[j] = '\0';
					
					status = generateNum(aa, &tmp);
					tmpM = (int)tmp;

					if (status == 'f')
					{
						printError(INVMARKS, lineNumber);
						
					}
					else if (status == 'F')
					{
						printError(EXTRACHARS, lineNumber);
						
					}
					else if (tmpM < -40 || tmpM > 160)
					{
						printError(MARKSRANGE, lineNumber);
						
					}
					else
					{
						rollNumber[validStudents] = tmpRoll;
						physics[validStudents] = tmpP;
						chemistry[validStudents] = tmpC;
						mathematics[validStudents] = tmpM;
						validStudents++;
						
					}
				}
			}
		}
		lineNumber++;
		currentLine = readInputLine();
	}


	if (validStudents == 0)
	{
		printError(NORECORDS, 0);
	}
	
	
	
	
	return(validStudents);
}







int meritList()
{
	int i, j, maxIndex, startIndex, rankCounter;
	int flag;
	float totalP = 0, totalC = 0, totalM = 0;
	int min, min2;
	int phy[MAXSTUDENTS], chem[MAXSTUDENTS], mat[MAXSTUDENTS];
	int clearedStuds;


	if (ranksRequired > validStudents)
	{
		printError(LESSSTUDENTS, 0);
	}

	for (i = 0; i < validStudents; i++)
	{
		totalP = totalP + physics[i];
		totalC = totalC + chemistry[i];
		totalM = totalM + mathematics[i];

		phy[i] = physics[i];
		chem[i] = chemistry[i];
		mat[i] = mathematics[i];

		
	}
	pAverage = totalP / validStudents;
	cAverage = totalC / validStudents;
	mAverage = totalM / validStudents;





	clearedStuds = ceil((float)(cutoffPercentile * validStudents) / 100);
	mergeSort(phy, 0, validStudents - 1);
	pCutoff = phy[clearedStuds - 1];
	
	mergeSort(chem, 0, validStudents - 1);
	cCutoff = chem[clearedStuds - 1];
	
	mergeSort(mat, 0, validStudents - 1);
	mCutoff = mat[clearedStuds - 1];
	

	if (pAverage < cAverage)
	{
		if (pAverage < mAverage)
		{
			min = 0;
			if (cAverage < mAverage)
			{
				min2 = 1;
			}
			else
			{
				min2 = 2;
			}
		}
		else if (pAverage == mAverage)
		{
			min = 2;
			min2 = 0;
		}
		else							
		{
			min = 2;
			min2 = 0;
		}
	}
	else if (pAverage == cAverage)
	{
		if (pAverage < mAverage)
		{
			min = 0;
			min2 = 1;
		}
		else if (pAverage == mAverage)
		{
			min = 2;
			min2 = 0;
		}
		else						
		{
			min = 2;
			min2 = 0;
		}
	}
	else									
	{	
		if (cAverage < mAverage)
		{
			min = 1;
			if (pAverage < mAverage)
			{
				min2 = 0;
			}
			else
			{
				min2 = 2;
			}
		}
		else if (cAverage == mAverage)
		{
			min = 2;
			min2 = 1;
		}
		else							
		{
			min = 2;
			min2 = 1;
		}

	}



	/*struct cut{
		int index;
		int rank;
		float avg;
	}s[3];


	s[0].index = 2;
	s[1].index = 0;
	s[2].index = 1;
	s[0].rank = 2;
	s[1].rank = 1;
	s[2].rank = 0;
	s[0].avg = mAverage;
	s[1].avg = pAverage;
	s[2].avg = cAverage;

	j = 0;

	for (i = 0; i<2; i++){
		for (j = 0; j<3 - i - 1; j++){
			if (s[j].avg>s[j + 1].avg || (s[j].avg == s[j + 1].avg && s[j].rank<s[j + 1].rank)){
				struct cut temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}


	min = s[0].index;
	min2 = s[1].index;*/


	j = 0;
	for (i = 0; i < validStudents; i++)
	{
		if (physics[i] >= pCutoff&&chemistry[i] >= cCutoff&&mathematics[i] >= mCutoff)
		{
			student[j].roll = rollNumber[i];
			student[j].marks[0] = physics[i];
			student[j].marks[1] = chemistry[i];
			student[j].marks[2] = mathematics[i];
			student[j].total = physics[i] + chemistry[i] + mathematics[i];
			student[j].index = i;
			j++;
		}
	}


	mergeSortMod(student, 0, j - 1, min, min2);


	
	
	for (i = 0; i < j; i++)
	{
		meritRank[i] = student[i].roll;
	}





	




	

	

	/*for (i = 0; i < validStudents; i++)
	{
		if (student[i].marks[0] >= pCutoff && student[i].marks[1] >= cCutoff && student[i].marks[2] >= mCutoff)
		{
			meritRank[i] = student[i].roll;
			rankCounter++;
		}
	}*/

	int totalMarks;
	/* Print merit list */
	int index = 0;
	while ((index < ranksRequired) && (meritRank[index] >= 0))
	{
		printMerit(index + 1, student[index].roll);
		/* Increment loop variables */
		index++;
	}
	/* If Loop terminates early : less valid Students after cutoff */
	if (ranksRequired > index) { printError(LESSSTUDENTS, 0); }
	else
	{   /* Extend Printing Beyond Rank Number for equal Marks till 10% more */
		//totalMarks = physics[index - 1] + chemistry[index - 1] + mathematics[index - 1];
		totalMarks = student[index - 1].total;
		while (index < ((int)(1.1 * ranksRequired)))
		{
			if (totalMarks == (student[index].total))  { printMerit(index + 1, student[index].roll); }
			/* Increment for Loop */
			index++;
		}
	}
	/* If students extend beyond 10% then print MORESTUDENTS error */
	if (totalMarks == (physics[index] + chemistry[index] + mathematics[index]))  { printError(MORESTUDENTS, 0); }

	/* Return the number of merit ranks printed */
	return(index);
}








char generateNum(char a[], long* num)
{
	long int ans = 0;
	int i = 0;
	int flag = 0;
	char retval = 's';
	while (a[i] == ' ')
	{
		i++;
	}
	if (a[i] == '-' && flag == 0)
	{
		flag = 1;
		i++;
		if (!(48 <= (int)a[i] && (int)a[i] <= 57))
		{
			retval = 'f';
		}
	}
	while ((a[i] != ' ' && a[i] != '\0') && retval == 's')
	{
		if (!(48 <= (int)a[i] && (int)a[i] <= 57))
		{
			if (ans == 0)
			{
				retval = 'f';
			}
			else
			{
				retval = 'F';
			}

		}
		else
		{
			ans = 10 * ans + (int)a[i] - (int)'0';
		}
		i++;
	}
	while (a[i] != '\0' && retval == 's')
	{
		if (a[i] != ' ')
		{
			retval = 'F';
		}
		i++;
	}
	if (flag == 1)
	{
		ans = -1 * ans;
	}
	*num = ans;
	return retval;
}






void mergedata(ranklist arr[], int l, int m, int r, int min, int smin)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	//ranklist *L, *R;
	ranklist L[n1], R[n2];
	//L = new ranklist[n1];
	//R = new ranklist[n2];
	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if ((L[i].total > R[j].total) || (L[i].total == R[j].total  && L[i].marks[min]>R[j].marks[min]) ||
			(L[i].total == R[j].total  && L[i].marks[min] == R[j].marks[min] && L[i].marks[smin]>R[j].marks[smin]) ||
			(L[i].total == R[j].total  && L[i].marks[min] == R[j].marks[min] && L[i].marks[smin] == R[j].marks[smin] &&
			L[i].roll<R[i].roll))
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSortMod(ranklist arr[], int l, int r, int min, int smin)
{
	if (l < r)
	{
		int m = l + (r - l) / 2; //Same as (l+r)/2, but avoids overflow for large l and h
		mergeSortMod(arr, l, m, min, smin);
		mergeSortMod(arr, m + 1, r, min, smin);
		mergedata(arr, l, m, r, min, smin);
	}
}




void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];
	//int *L = new int[n1];
	//int *R = new int[n2];
	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2; //Same as (l+r)/2, but avoids overflow for large l and h
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

