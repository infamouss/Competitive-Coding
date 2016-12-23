// Balanced Contest or Not.cpp : Defines the entry point for the console application.
//


#include <stdio.h>

typedef struct
{
	int a, b;
} node;




void sort(node arr[])
{
	int i, j;
	node tmp, min;
	int pos;
	for (i = 0;i < 4;i++)
	{
		pos = i;
		min = arr[i];
		for (j = i + 1;j < 5;j++)
		{
			if (min.a > arr[j].a)
			{
				min = arr[j];
				pos = j;
			}
		}
		if (pos != i)
		{
			tmp = arr[i];
			arr[i] = arr[pos];
			arr[pos] = tmp;
		}
	}
}





int main()
{
	int i;
	node nd[5];
	for (i = 0;i < 5;i++)
	{
		scanf("%d%d", &nd[i].a, &nd[i].b);
	}
	sort(nd);
	for (i = 0;i < 4;i++)
	{
		if (nd[i].b>nd[i + 1].b)
		{
			printf("0");
			return 0;
		}
	}
	printf("1");
	return 0;
}

