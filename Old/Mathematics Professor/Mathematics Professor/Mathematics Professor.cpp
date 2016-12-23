// Mathematics Professor.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

long long der[1000001];

long long countDer(long long n)
{
	
	
	der[0] = 1;
	der[1] = 0;
	der[2] = 1;

	
	for (int i = 3; i <= n; ++i)
		der[i] = (((i - 1) % 1000000007)*((der[i - 1] + der[i - 2]) % 1000000007)) % 1000000007;

	return der[n];
}



int main()
{
	long long N;
	scanf("%lld", &N);
	printf("%lld\n", countDer(N));
	return 0;
}

