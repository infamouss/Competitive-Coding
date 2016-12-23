// Help Sumit.cpp : Defines the entry point for the console application.
// url:https://www.codechef.com/SRMC2016/problems/DRCTNSRM

#include <stdio.h>


int main()
{
	int T, i, x, y;
	char ip[51];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", ip);
		x = y = i = 0;
		while (ip[i] != '\0')
			switch (ip[i++])
			{
			case 'N':
				y++;
				break;
			case 'S':
				y--;
				break;
			case 'E':
				x++;
				break;
			case 'W':
				x--;
				break;
			}
		if (y > 0)
			printf("NORTH");
		else if (y < 0)
			printf("SOUTH");
		if (x > 0)
			printf("EAST");
		else if (x < 0)
			printf("WEST");
		printf("\n");
	}
	return 0;
}

