// Lisa's Workbook.cpp : Defines the entry point for the console application.
// url:https://www.hackerrank.com/challenges/bear-and-workbook

#include <stdio.h>
#include <math.h>


int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int answer = 0;
	int page = 1;
	for (int chapter = 1; chapter <= n; ++chapter)
	{
		int problems;
		scanf("%d", &problems);
		for (int index = 1; index <= problems; ++index)
		{
			if (index == page)
				answer++;
			if (index == problems || index % k == 0)
				++page;
		}
	}
	printf("%d\n", answer);
	return 0;
}

