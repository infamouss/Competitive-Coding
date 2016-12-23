// Square in numbers.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/LTIME37/problems/SQNUMBF

#include <stdio.h>
#include <cmath>



unsigned long long GCD(unsigned long long a, unsigned long long b)
{
	if (a%b == 0)
		return b;
	return GCD(b, a%b);
}




unsigned long long isSquare(unsigned long long a)
{
	unsigned i;

	for (i = 2;i*i <= a;i++)
	{
		if (a % (i*i) == 0)
			return a;
	}






	return 0;
}



unsigned long long ip[100];

int main()
{
	int T, N, i, j, flag;
	unsigned long long ans;
	scanf("%d", &T);
	while (T--)
	{
		flag = 0;
		ans = 0;
		scanf("%d", &N);
		for (i = 0;i < N;i++)
		{
			scanf("%llu", &ip[i]);

		}
		for (i = 0;i < N - 1 && flag == 0;i++)
		{
			for (j = i + 1;j < N&&flag == 0;j++)
			{
				ans= GCD(ip[i], ip[j]);
				if (ans != 1)
				{
					flag = 1;
					printf("%llu\n", ans);
				}
			}
		}

	}




	return 0;
}

