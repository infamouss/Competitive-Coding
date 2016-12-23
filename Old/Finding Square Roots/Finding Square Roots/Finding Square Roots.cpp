// Finding Square Roots.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>


int main()
{
	int T, num;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &num);
		printf("%d\n", (int)sqrt(num));
	}
    return 0;
}

