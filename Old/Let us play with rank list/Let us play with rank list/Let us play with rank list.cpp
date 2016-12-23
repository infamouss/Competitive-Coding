#include<stdio.h>

int main()
{
	int t, i;
	long n, s;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		
		scanf("%d%d", &n,&s);
		
		while (s>0)
		{
			s = s - n;
			n--;
		}
		
		printf("%d\n", n);
	}
	return 0;
}