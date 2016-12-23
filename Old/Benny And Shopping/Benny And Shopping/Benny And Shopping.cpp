// Benny And Shopping.cpp : Defines the entry point for the console application.
// url : https://www.hackerearth.com/june-easy-16/algorithm/benny-and-shopping/

#include <stdio.h>
#include <string.h>


int main()
{
	int T, i, flag = 0;
	char ip[1001];
	scanf("%d", &T);
	
	while (T--)
	{
		scanf(" %[^\n]s", ip);
		
		i = 0;
		while (ip[i] != '$')
		{
			i++;
		}
		i++;
		while (ip[i] != '\0' && (ip[i] == ' ' || ip[i] == '0'))
		{
			i++;
		}
		printf("$");
		if (ip[i] >= '1'&&ip[i] <= '9')
		{
			printf("%c", ip[i]);
			i++;

			while (ip[i] != '\0' && (ip[i] == ' ' || (ip[i] >= '0'&&ip[i]<='9')))
			{
				if(ip[i]!=' ')
				printf("%c", ip[i]);
				i++;
			}
		}
		else
		{
			printf("0");
		}
		printf("\n");
	}
	return 0;
}

