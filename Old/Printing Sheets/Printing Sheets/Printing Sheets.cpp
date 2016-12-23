// Printing Sheets.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{

	long int N;
	scanf("%ld", &N);
	if (N % 2 == 0 || N % 3 == 0)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}


	return 0;
}

