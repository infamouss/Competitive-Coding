// Chef and digits of a number.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/SEPT16/problems/LONGSEQ

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int T;
	long i, n0, n1;
	char ip[100001];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", ip);
		i = n0 = n1 = 0;
		while (ip[i] != '\0')
		{
			if (ip[i] == '0')
				n0++;
			else
				n1++;
			i++;
		}
		if (n0 == 1 || n1 == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

