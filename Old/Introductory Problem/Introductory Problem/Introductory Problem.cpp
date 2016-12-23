// Introductory Problem.cpp : Defines the entry point for the console application.
// url:https://www.codechef.com/SRMC2016/problems/INTROSRM

#include <stdio.h>


unsigned long long rev(unsigned long long n)
{

	unsigned long long ans = 0;
	while (n != 0)
	{
		ans = 10*ans + n % 10;
		n /= 10;
	}
	return ans;
}



int main()
{
	long T;
	int i;
	unsigned long long ip;
	scanf("%ld", &T);
	while (T--)
	{
		scanf("%llu", &ip);
		printf("%lld\n", rev(ip));
		
	}
	return 0;
}

