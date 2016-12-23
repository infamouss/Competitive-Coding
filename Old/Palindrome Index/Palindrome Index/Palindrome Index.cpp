// Palindrome Index.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>


int main()
{
	long len, i, j, I, J;
	int T, flag;
	char str[100006];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str);
		len = strlen(str);
		i = 0;
		j = len - 1;
		flag = 0;
		while (str[i] == str[j] && i < len / 2)
		{
			i++;
			j--;
		}
		if (i == len / 2)
		{
			printf("-1\n");
		}
		else
		{
			I = i;
			J = j;
			--j;
			while (str[i] == str[j] && i < len / 2)
			{
				i++;
				j--;
			}

			if (i == len / 2)
			{
				printf("%ld\n", J);
			}
			else
			{
				printf("%ld\n", I);
			}
		}
	}
	return 0;
}

