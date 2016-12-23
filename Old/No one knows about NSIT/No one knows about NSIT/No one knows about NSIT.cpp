// No one knows about NSIT.cpp : Defines the entry point for the console application.
//url:https://www.codechef.com/ASNE2016/problems/STUD2

#include <stdio.h>


int main()
{
	int T, N, C, i, j;
	long ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &C);
		ans = C*(N - 1) + (N - 2)*(2 * 2 + (N - 3) * 4) + 2 * (1 + (N - 2) * 2);
		printf("%ld\n", ans);
	}
	return 0;
}

