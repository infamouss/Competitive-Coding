// Caesar Cipher.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int n, k, i, tmp;
	char str[101];
	scanf("%d%s%d", &n, str, &k);
	for (i = 0;i < n;i++)
	{
		tmp = str[i] - 'a';
		if (tmp >= 0 && tmp <= 25)
		{
			tmp = tmp + k;
			printf("%c", tmp % 26 + 'a');
		}
		else
		{
			tmp = str[i] - 'A';
			if (tmp >= 0 && tmp <= 25)
			{
				tmp = tmp + k;
				printf("%c", tmp % 26 + 'A');
			}
			else
			{
				printf("%c", str[i]);
			}
		}
	}


	return 0;
}

