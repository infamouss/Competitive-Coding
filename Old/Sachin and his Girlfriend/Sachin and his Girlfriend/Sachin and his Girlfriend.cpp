// Sachin and his Girlfriend.cpp : Defines the entry point for the console application.
//url : https://www.codechef.com/BIGO2016/problems/SACHGF

#include <stdio.h>


int main()
{
	int T, isFound[1007] = { 0 };
	long long N;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld", &N);
		if (isFound[N % 1007] == 0)
		{
			isFound[N % 1007] = 1;
			printf("%lld\n", N % 1007);
		}	
	}
	return 0;
}

