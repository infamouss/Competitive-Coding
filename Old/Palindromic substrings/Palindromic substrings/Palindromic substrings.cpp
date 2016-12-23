// Palindromic substrings.cpp : Defines the entry point for the console application.
//url:https://www.codechef.com/MARCH16/problems/STRPALIN

#include <stdio.h>


int main()
{
	int T, i, flag;
	char A[1001], B[1001];
	scanf("%d", &T);
	while (T--)
	{
		int ah[26] = { 0 }, bh[26] = { 0 };
		scanf("%s%s", A, B);

		i = 0;
		while (A[i] != '\0')
		{
			ah[A[i] - 'a']++;
			i++;
		}
		i = 0;
		while (B[i] != '\0')
		{
			bh[B[i] - 'a']++;
			i++;
		}
		for (i = flag = 0;i < 26 && flag == 0;i++)
		{
			if (ah[i] > 0 && bh[i] > 0)
			{
				flag = 1;
			}
		}
		printf("%s\n", (flag == 0) ? "No" : "Yes");
	}
	return 0;
}

