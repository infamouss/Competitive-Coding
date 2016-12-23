// Little Elephant and Candies.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, N, Ai;
	long C;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%ld", &N, &C);
		while (N--)
		{
			scanf("%d", &Ai);
			C -= Ai;
		}
		printf("%s\n", (C < 0) ? "No" : "Yes");
	}
    return 0;
}

