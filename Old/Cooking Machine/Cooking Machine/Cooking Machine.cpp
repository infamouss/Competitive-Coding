// Cooking Machine.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>


bool isGood(long n)
{
	float root = log2(n);
	if (root == (int)root)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	int T, ans;
	long A, B;
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%ld%ld", &A, &B);
		while (!isGood(A))
		{
			A /= 2;
			ans++;
		}
		ans += ((int)log2(B) - (int)log2(A) > 0) ? (int)log2(B) - (int)log2(A) : (int)log2(A) - (int)log2(B);
		printf("%d\n", ans);
	}
    return 0;
}

