// Faded Palindromes.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/SEPT16/problems/LEXOPAL

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

int main()
{
	int T, flag;
	long i, j;
	string ip;
	scanf("%d", &T);
	while (T--)
	{
		cin >> ip;
		j = ip.size() - 1;
		i = flag = 0;
		while (i <= j&&flag == 0)
		{
			if (ip[i] == '.'&&ip[j] == '.')
				ip[i] = ip[j] = 'a';
			else if (ip[i] == '.')
				ip[i] = ip[j];
			else if (ip[j] == '.')
				ip[j] = ip[i];
			else if (ip[i] != ip[j])
				flag = 1;
			i++;
			j--;
		}
		if (flag == 0)
			cout << ip << endl;
		else
			printf("-1\n");
	}
	return 0;
}

