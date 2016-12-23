// Time Conversion.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	char ip[11];
	scanf("%s", ip);

	if (ip[8] == 'A')
	{
		if (ip[0] == '1'&&ip[1] == '2')
		{
			printf("00");
		}
		else
		{
			if ((10 * (ip[0] - '0') + ip[1] - '0') / 10 == 0)
			{
				printf("0");
			}
			printf("%d", 10 * (ip[0] - '0') + ip[1] - '0');
		}
	}
	else
	{
		if (ip[0] == '1'&&ip[1] == '2')
		{
			printf("12");
		}
		else
		{
			printf("%d", 10 * (ip[0] - '0') + ip[1] - '0' + 12);
		}
	}



	printf(":%c%c:%c%c", ip[3], ip[4], ip[6], ip[7]);
	return 0;
}

