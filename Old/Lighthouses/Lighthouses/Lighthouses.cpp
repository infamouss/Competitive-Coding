// Lighthouses.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	long N, i, minX, minXY, minY, minYX, islandX, islandY, X, Y;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld", &N);
		scanf("%ld%ld", &X, &Y);
		minX=minYX = X;
		minY=minXY = Y;
		islandX = islandY = 1;
		for (i = 1;i < N;i++)
		{
			scanf("%ld%ld", &X, &Y);
			if (minX > X)
			{
				minX = X;
				minXY = Y;
				islandX = i + 1;
			}
			else if (minX == X)
			{
				if (minXY > Y)
				{
					minXY = Y;
					islandX = i + 1;
				}
			}
			if (minY > Y)
			{
				minY = Y;
				minYX = X;
				islandY = i + 1;
			}
			else if (minY == Y)
			{
				if (minYX > X)
				{
					minYX = X;
					islandY = i + 1;
				}
			}
		}
		if (islandX == islandY)
		{
			printf("1\n%ld NE\n", islandX);
		}
		else
		{
			printf("2\n%ld NE\n%ld NE\n", islandX, islandY);
		}
	}
    return 0;
}

