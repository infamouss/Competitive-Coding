// Abbreviation.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/world-codesprint-6/challenges/abbr

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int q, i, j, flag;
	char a[1001], b[1001];
	scanf("%d", &q);
	while (q--)
	{
		scanf("%s%s", a, b);
		i = j = flag = 0;

		while (a[i] != '\0'&&b[j] != '\0')
		{

			if (a[i] == b[j]||a[i]-32==b[j])
			{
				j++;
			}


			i++;
		}

		if (b[j] == '\0')
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}

	}






	return 0;
}

