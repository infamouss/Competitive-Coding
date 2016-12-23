// BinarySearch.cpp : Defines the entry point for the console application.
//

#include <stdio.h>



int binarySearch(int array[], int num, int start, int end)
{
	int mid = (start + end) / 2;
	if (start > end)
	{
		return -1;
	}
	if (num == array[mid])
	{
		return mid;
	}
	else if (num < array[mid])
	{
		return binarySearch(array, num, start, mid - 1);
	}
	else
	{
		return binarySearch(array, num, mid + 1, end);
	}
}




int main()
{
	int num;
	int a[10] = { 1, 4, 4, 8, 10, 15, 17, 20, 30};
	scanf("%d", &num);
	int searchVal = binarySearch(a, num, 0, 8);
	if (searchVal < 0)
	{
		printf("not found\n");
	}
	else
		printf("%d\n", a[searchVal]);
	return 0;
}
