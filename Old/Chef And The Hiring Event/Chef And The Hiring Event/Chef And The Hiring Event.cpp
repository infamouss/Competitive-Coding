// Chef And The Hiring Event.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/JUNE16/problems/CHEARMY

#include <stdio.h>
//#include <cmath>
//#include <functional>
//#include <algorithm>
//#include <set>
//#include <vector>
//#include <iostream>


using namespace std;

int strlen(char *s)
{
	char *start;
	start = s;
	while (*s != 0)
	{
		++s;
	}
	return s - start;
}

char *reverse(char *str)
{
	char c, *front, *back;

	if (!str || !*str)
		return str;
	for (front = str, back = str + strlen(str) - 1;front < back;front++, back--)
	{
		c = *front;*front = *back;*back = c;
	}
	return str;
}

void itoa(long long num, char* str, int base)
{
	int i = 0;
	bool isNegative = false;
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		
	}
	if (num < 0 && base == 10)
	{
		isNegative = true;
		num = -num;
	}
	while (num != 0)
	{
		int rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}
	if (isNegative)
		str[i++] = '-';

	str[i] = '\0'; 
	reverse(str);
}

int main()
{
	long T;
	long long K;
	char buff[100];
	//cin >> T;
	scanf("%ld", &T);
	while (T--)
	{
		//cin >> K;
		scanf("%lld", &K);
		K--;
		itoa(K, buff, 5);
		int i = 0;
		while (buff[i] != '\0')
		{
			printf("%d", (buff[i] - '0') * 2);
			i++;
		}
		printf("\n");
	}
	return 0;
}

