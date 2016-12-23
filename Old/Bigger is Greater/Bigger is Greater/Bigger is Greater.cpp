// Bigger is Greater.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>

void sort(char a[], int start, int end)
{
	char min, tmp;
	int i, j, index;
	for (i = start; i < end; i++)
	{
		min = a[i];
		index = i;
		for (j = i + 1; j <= end; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				index = j;
			}
		}
		if (index != i)
		{
			tmp = a[i];
			a[i] = a[index];
			a[index] = tmp;
		}
	}
}


int main()
{
	long T;
	int len, flag, i, j;
	char str[101], tmp;
	scanf("%ld", &T);
	while (T--)
	{
		scanf("%s", str);
		len = strlen(str);
		flag = 0;
		for (i = len - 1;i > 0 && flag == 0;i--)
		{
			for (j = i - 1;j >= 0 && flag == 0;j--)
			{
				if (str[i] > str[j])
				{
					flag = 1;
					tmp = str[i];
					str[i] = str[j];
					str[j] = tmp;
					sort(str, j + 1, len - 1);
				}
			}
		}
		if (flag == 0)
		{
			printf("no answer\n");
		}
		else
		{
			printf("%s\n", str);
		}
	}
	return 0;
}