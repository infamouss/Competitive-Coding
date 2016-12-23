// Studying Alphabet.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/LTIME39/problems/ALPHABET

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

int main()
{
	char s[27], ip[13];
	set<char> chars;
	int N, i, flag;
	scanf("%s", s);
	i = 0;
	while (s[i]!='\0')
	{
		chars.insert(s[i]);
		i++;
	}
	scanf("%d", &N);
	while (N--)
	{
		scanf("%s", ip);
		i = flag = 0;
		while (ip[i] != '\0' &&flag == 0)
		{
			if (chars.find(ip[i]) == chars.end())
			{
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}

