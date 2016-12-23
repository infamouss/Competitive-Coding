// Song of Pi.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>


int main()
{
	int T, i, j, wc, flag = 0;
	char ref[] = "31415926535897932384626433833", ip[501];
	scanf("%d", &T);
	gets_s(ip);
	while (T--)
	{
		gets_s(ip);
		i = 0;
		j = 0;
		wc = 0;
		flag = 0;
		while (ip[i] != '\0'&&flag == 0)
		{
			if ((ip[i] >= 'a'&&ip[i] <= 'z') || (ip[i] >= 'A'&&ip[i] <= 'Z'))
			{
				wc++;
			}
			else
			{
				if (wc != ref[j] - '0')
				{
					flag = 1;
				}
				
				j++;
				wc = 0;
			}
			i++;
		}
		if (ip[i] == '\0')
		{
			if (wc != ref[j] - '0')
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			printf("It's a pi song.\n");
		}
		else
		{
			printf("It's not a pi song.\n");
		}
	}
	return 0;
}

