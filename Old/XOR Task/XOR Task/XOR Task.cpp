// XOR Task.cpp : Defines the entry point for the console application.
//

#include <stdio.h>




int main()
{
	int T;
	long long N, An,xored;
	char str[40];
	char expArr[40];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld", &N, &An);
		if (N % 2 == 1)
		{
			xored = (N % 4 == 1) ? 1 : 0;
		}
		else
		{
			xored = (N % 4 == 0) ? N : N + 1;
		}
		printf("%lld\n", xored^An);
	}
	return 0;
}





/*
int main()
{
long long int t,n,x;

scanf("%lld",&t);

while(t--)
{
scanf("%lld%lld",&n,&x);

long long int i,xorr=0;

if (n % 2 == 1 ){
xorr = (n % 4 == 1) ? 1 : 0;
} else {
xorr = (n % 4 == 0) ? n : n + 1;
}
printf("%lld\n",xorr^x);
}
}
*/

