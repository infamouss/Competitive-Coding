// Yet Another Number Game.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>



int main()
{
	int T;
	long N;
	char name[2][6] = { "ALICE","BOB" };
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld", &N);
		printf("%s\n", (N % 2 == 0) ? name[0] : name[1]);
		
	}
    return 0;
}

