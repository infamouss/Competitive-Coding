// Big File System Search.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>



void insertHeap(int current, int low, int high, int a[])
{
	int large, done = 0;
	large = 2 * low + 1;
	while (large <= high && !done)
	{
		if (large < high && a[large] < a[large + 1])
		{
			large++;
		}
		if (current > a[large])
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
void buildHeap(int a[], int n)
{
	int low;
	for (low = n / 2 - 1; low >= 0; low--)
	{
		insertHeap(a[low], low, n - 1, a);
	}
}
void heapSort(int a[], int n)
{
	int lu, current;
	buildHeap(a, n);
	for (lu = n - 1; lu >= 1; lu--)
	{
		current = a[lu];
		a[lu] = a[0];
		insertHeap(current, 0, lu - 1, a);
	}
}




int main()
{
	int i, j, k, l;





	int numFiles;
	int* fileSize;
	int** files;

	scanf("%d", &numFiles);
	fileSize = (int*)malloc(sizeof(int)*numFiles);
	files = (int**)malloc(sizeof(int*)*numFiles);



	for (i = 0; i < numFiles; i++)
	{
		scanf("%d", &fileSize[i]);
		files[i] = (int*)malloc(sizeof(int)*fileSize[i]);
		for (j = 0; j < fileSize[i]; j++)
		{
			scanf("%d", &files[i][j]);
		}
		heapSort(files[i], fileSize[i]);
	}





	int numQueries;
	int* queryType;
	int* querySize;
	int** query;


	scanf("%d", &numQueries);
	queryType = (int*)malloc(sizeof(int)*numQueries);
	querySize = (int*)malloc(sizeof(int)*numQueries);
	query = (int**)malloc(sizeof(int*)*numQueries);

	for (i = 0; i < numQueries; i++)
	{
		scanf("%d", &queryType[i]);
		scanf("%d", &querySize[i]);
		query[i] = (int*)malloc(sizeof(int)*querySize[i]);
		for (j = 0; j < querySize[i]; j++)
		{
			scanf("%d", &query[i][j]);
		}
		heapSort(query[i], querySize[i]);
	}



	int count;
	int cont;
	int flag;


	for (i = 0; i < numQueries; i++)
	{
		count = 0;
		for (j = 0; j < numFiles; j++)
		{
			k = l = 0;
			cont = 0;
			flag = 0;
			switch (queryType[i])
			{
			case 1:							//all

				while (k < querySize[i] && l < fileSize[j])
				{
					if (query[i][k] == files[j][l])
					{
						cont++;
						k++;
						l++;
					}
					else if (query[i][k] < files[j][l])
					{
						k++;
					}
					else
					{
						l++;
					}
				}
				if (cont == querySize[i])
				{
					count++;
				}

				break;
			case 2:							//atleast 1
				
				while (k < querySize[i] && l < fileSize[j] && flag == 0)
				{
					if (query[i][k] == files[j][l])
					{
						flag = 1;
						count++;
					}
					else if (query[i][k] < files[j][l])
					{
						k++;
					}
					else
					{
						l++;
					}
				}
				break;
			case 3:							//all but 1
				
				while (k < querySize[i] && l < fileSize[j])
				{
					if (query[i][k] == files[j][l])
					{
						cont++;
						k++;
						l++;
					}
					else if (query[i][k] < files[j][l])
					{
						k++;
					}
					else
					{
						l++;
					}
				}
				if (cont <= querySize[i] - 1 && cont > 0)
				{
					count++;
				}
				break;
			}
		}
		printf("%d\n", count);
	}








	return 0;
}