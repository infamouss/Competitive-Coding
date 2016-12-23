// Funny String.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int T, i, j, len, fun;
	char str[10001];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str);
		len = strlen(str);
		fun = 0;
		for (i = 1, j = len - 2;i < len&&fun == 0;i++, j--)
		{
			if (abs(str[i] - str[i - 1]) != abs(str[j] - str[j + 1]))
			{
				fun = 1;
			}
		}
		printf("%sFunny\n", (fun == 0) ? "" : "Not ");
	}
	return 0;
}

