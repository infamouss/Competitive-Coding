// Lonely Integer.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

int main()
{
	int n, i, tmp, count[101] = { 0 }, flag;
	scanf("%d", &n);
	for (i = 0;i < n;i++)
	{
		scanf("%d", &tmp);
		count[tmp]++;
	}
	i = 0;
	while (i != -1)
	{
		if (count[i] == 1)
		{
			printf("%d", i);
			i = -2;
		}
		i++;
	}




	return 0;
}

