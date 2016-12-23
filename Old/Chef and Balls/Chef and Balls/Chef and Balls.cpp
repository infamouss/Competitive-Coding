// Chef and Balls.cpp : Defines the entry point for the console application.
// https://www.codechef.com/MAY16/problems/CHBLLS

#include <stdio.h>


int main()
{
	int flag;
	printf("1\n");
	printf("3 2 5 5\n");
	printf("3 3 3 4\n");
	fflush(stdout);
	scanf("%d", &flag);
	printf("2\n");
	switch (flag)
	{
	case 0:
		printf("1\n");
		break;
	case 1:
		printf("2\n");
		break;
	case -1:
		printf("4\n");
		break;
	case 2:
		printf("5\n");
		break;
	case -2:
		printf("3\n");
		break;
	}
	return 0;
}

