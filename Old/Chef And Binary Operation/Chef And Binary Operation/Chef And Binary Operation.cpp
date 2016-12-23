// Chef And Binary Operation.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/JUNE16/problems/BINOP

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <set>


using namespace std;
char A[1000001], B[1000001];
int main()
{
	long T, i, req1, req0;
	int zero, one, notEqual;
	
	cin >> T;
	while (T--)
	{
		cin >> A >> B;
		i = 0;
		zero = one = 0;
		req0 = req1 = 0;
		while (A[i] != '\0')
		{
			if (A[i] == '1')
				one = 1;

			if (A[i] == '0')
				zero = 1;

			if (A[i] != B[i])
			{
				if (B[i] == '0')
					req1++;
				else
					req0++;
			}
			i++;
		}

		if (zero == 0 || one == 0)
		{
			printf("Unlucky Chef\n");
		}
		else
		{
			printf("Lucky Chef\n");
			long ans;
			ans = min(req0, req1);
			req0 -= ans;
			req1 -= ans;
			ans += max(req0, req1);
			printf("%ld\n", ans);
		}
	}
	return 0;
}

