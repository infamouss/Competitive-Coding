// MergeSort Modified.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


typedef struct list
{
	long roll;
	int marks[3];
	int total;
}ranklist;


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}



void mergedata(list arr[], int l, int m, int r, int min, int smin)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	ranklist *L, *R;
	L = new ranklist[n1];
	R = new ranklist[n2];
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

/* l is for left index and r is right index of the sub-array
of arr to be sorted */
void mergeSortMod(list arr[], int l, int r, int min, int smin)
{
	if (l < r)
	{
		int m = l + (r - l) / 2; //Same as (l+r)/2, but avoids overflow for large l and h
		mergeSortMod(arr, l, m, min, smin);
		mergeSortMod(arr, m + 1, r, min, smin);
		mergedata(arr, l, m, r, min, smin);
	}
}
