// HeapSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



typedef struct
{
	int frequency;
	int ranking;
	int huffmanCode;
	char character;
} huffmanElement;




void heapSort(huffmanElement a[], int n);
void insertHeap(huffmanElement current, int low, int high, huffmanElement a[]);
void buildHeap(huffmanElement a[], int n);
void selectionSort(huffmanElement a[], int n);


void frequency(huffmanElement array[], char string[]);




int _tmain(int argc, _TCHAR* argv[])
{
	/*int a[10] = { 5, 6, 9, 8, 2, 1, 6, 8, 7, 6 };

	heapSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}*/


	int i, j, k;
	char string[5000];
	huffmanElement array[27];
	array[0].frequency = 0;
	array[0].huffmanCode = 0;
	array[0].ranking = -1;
	array[0].character = ' ';
	for (i = 1; i < 27; i++)
	{
		array[i].frequency = 0;
		array[i].huffmanCode = 0;
		array[i].ranking = -1;
		array[i].character = (char)((int)'a' + i - 1);
	}
	gets(string);


	frequency(array, string);


	/*for (i = 0; i < 27; i++)
	{
		if (i == 0)
		{
			printf("frequency of character ' ' is %d\n", array[i].frequency);
		}
		else
		{
			printf("frequency of character '%c' is %d\n", char((int)'a' + i - 1), array[i].frequency);
		}
	}*/


	heapSort(array, 27);


	//selectionSort(array, 27);


	for (i = 0; i < 27; i++)
	{
		/*if (i == 0)
		{
			printf("frequency of character ' ' is %d\n", array[i].frequency);
		}
		else
		{
			printf("frequency of character '%c' is %d\n", char((int)'a' + i - 1), array[i].frequency);
		}*/
		printf("frequency of character '%c' is %d\n", array[i].character, array[i].frequency);
	}



	printf("%d", (int)'a');


	return 0;
}





void heapSort(huffmanElement a[], int n)
{
	int lu;
	huffmanElement current;
	buildHeap(a, n);
	for (lu = n - 1; lu >= 1; lu--)
	{
		current = a[lu];
		a[lu] = a[0];
		insertHeap(current, 0, lu - 1, a);
	}
}




void insertHeap(huffmanElement current, int low, int high, huffmanElement a[])
{
	int large, done = 0;
	large = 2 * low + 1;
	while (large <= high && !done)
	{
		if (large < high && a[large].frequency < a[large + 1].frequency)
		{
			large++;
		}
		if (current.frequency > a[large].frequency)
		{
			done = 1;
		}
		else
		{
			a[low] = a[large];
			low = large;
			large = 2 * low + 1;
		}
	}
	a[low] = current;
}



void buildHeap(huffmanElement a[], int n)
{
	int low;
	for (low = n / 2 - 1; low >= 0; low--)
	{
		insertHeap(a[low], low, n - 1, a);
	}
}






void frequency(huffmanElement array[], char string[])
{
	int i, j, k, tmp;
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
		{
			array[0].frequency++;
		}
		else if ((int)string[i] <= (int)'z' && (int)string[i] >= (int)'a')
		{
			array[(int)string[i] - (int)'a' + 1].frequency++;
		}
		i++;
	}
}



void selectionSort(huffmanElement a[], int n)
{
	int i, j, minIndex;
	huffmanElement tmp;
	for (i = 0; i < n - 1; i++)
	{
		//minIndex = i;

		for (j = i + 1; j < n; j++)
		{
			if (a[i].frequency > a[j].frequency)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
				//minIndex = j;
			}
		}
		/*if (minIndex != i)
		{
			tmp = a[i];
			a[i] = a[minIndex];
			a[minIndex] = tmp;
		}*/
	}
}



