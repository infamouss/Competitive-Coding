// Vipul - The Bracket Checker.cpp : Defines the entry point for the console application.
// url:https://www.codechef.com/SRMC2016/problems/BRCKTSRM

#include <stdio.h>


int main()
{
	int T, i, check;
	char ip[61];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", &ip);
		i = check = 0;
		while (ip[i] != '\0'&&check >= 0)
		{
			(ip[i] == '(') ? check++ : check--;
			i++;
		}
		printf("%s\n", (check == 0) ? "YES" : "NO");
	}
	return 0;
}

