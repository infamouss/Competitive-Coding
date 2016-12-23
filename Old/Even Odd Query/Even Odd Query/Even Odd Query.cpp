// Even Odd Query.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>


int A[100001];

int find(int x, int y)
{
	if (x>y) return 1;
	int ans;
	ans = pow(A[x], find(x + 1, y));
	return ans;
}


int main()
{
	long N, Q, ans, i, x, y;
	scanf("%ld", &N);
	for (i = 1;i <= N;i++)
	{
		scanf("%d", &A[i]);
	}
	scanf("%ld", &Q);


	while (Q--)
	{
		scanf("%ld%ld", &x, &y);
		printf("%s\n", (find(x, y) % 2) ? "Odd" : "Even");
	}



    return 0;
}

