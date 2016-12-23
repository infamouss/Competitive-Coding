// Lucky Four.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	long T, n;
	int ans;
	scanf("%ld", &T);
	while (T--)
	{
		scanf("%ld", &n);
		ans = 0;
		while (n)
		{
			if (n % 10 == 4)
			{
				ans++;
			}
			n /= 10;
		}
		printf("%d\n", ans);
	}
    return 0;
}

