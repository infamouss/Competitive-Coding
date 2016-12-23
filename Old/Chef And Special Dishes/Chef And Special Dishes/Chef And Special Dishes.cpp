// Chef And Special Dishes.cpp : Defines the entry point for the console application.
//url:https://www.codechef.com/MARCH16/problems/CHEFSPL

#include <stdio.h>
#include <string.h>

char ip[2000003];

int main()
{
	long D, i, j, len, I, J;
	int flag;
	scanf("%ld", &D);
	while (D--)
	{
		scanf("%s", ip);
		len = strlen(ip);
		
		i = 0;
		if (len == 1)
		{
			printf("NO\n");
		}
		else if (len % 2 == 0)
		{
			j = len / 2;
			while (ip[j] != '\0'&&ip[i] == ip[j])
			{
				i++;
				j++;
			}
			if (ip[j] == '\0')
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		else
		{
			j = len / 2;
			flag = 0;

			while (i < len / 2 && flag < 2)
			{
				if (ip[i] != ip[j])
				{
					flag++;
					i--;
				}
				i++;
				j++;
			}

			if (flag == 2)
			{
				i = 0;
				j = len / 2 + 1;
				flag = 0;


				while (j < len && flag < 2)
				{
					if (ip[i] != ip[j])
					{
						flag++;
						j--;
					}
					i++;
					j++;
				}
				if (flag == 2)
				{
					printf("NO\n");
				}
				else
				{
					printf("YES\n");
				}

			}
			else
			{
				printf("YES\n");
			}
		}
	}
	return 0;
}

