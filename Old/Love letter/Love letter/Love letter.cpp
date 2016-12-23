// Love letter.cpp : Defines the entry point for the console application.
//
			   
#include <stdio.h>


void itoa(int N,char str[],int base)
{
	int i = 0;
	while (N)
	{
		if (N%base == 0)
		{
			str[i] = '0';
		}
		else
		{
			str[i] = '1';
		}
		i++;
		N /= base;
	}
	str[i] = '\0';
}


int strlen(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}


int main()
{
	int T, N, flag;
	long K;
	char buff[100];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%ld", &N, &K);
		itoa(K, buff, 2);
		flag = 0;
		for (int i = 0;i < N&&flag == 0;i++)
		{
			if (buff[i] != '1')
				flag = 1;
		}
		printf("%s\n", (flag == 1) ? "NO" : "YES");
	}
	return 0;
}

