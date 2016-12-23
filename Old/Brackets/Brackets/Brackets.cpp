// Brackets.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

long maxBalance(char str[])
{
	long i, balance, maxBal;
	balance = maxBal = i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
		{
			balance++;
		}
		else
		{
			balance--;
		}
		if (balance > maxBal)
		{
			maxBal = balance;
		}
		i++;
	}
	return maxBal;
}

int main()
{
	int T;
	char str[100001];
	long maxBal, i;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str);
		maxBal = maxBalance(str);
		for (i = 0;i < maxBal;i++)
		{
			printf("(");
		}
		for (i = 0;i < maxBal;i++)
		{
			printf(")");
		}
		printf("\n");
	}
    return 0;
}

