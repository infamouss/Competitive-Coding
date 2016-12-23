// Chocolate Feast.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	long n, c, m, ans;

	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%ld%ld%ld", &n, &c, &m);
		ans = n / c;
		n = ans;
		while (n >= m)
		{

			ans += n / m;
			n = n / m + n % m;
			
		}
		printf("%ld\n", ans);
	}

	return 0;
}

