#include "stdafx.h"
#include<stdio.h>
#include<math.h>
int main()
{
	float n, ans1, ans2, error;
	scanf_s("%f",&n);
	ans2 = n / 2;
	error = 1;
	while (error>.01)
	{
		ans1 = ans2;
		ans2 = (ans1 + n / ans1) / 2;
		error = abs(ans2 - ans1);
	}
	printf("%f",ans2);
	return 0;
}