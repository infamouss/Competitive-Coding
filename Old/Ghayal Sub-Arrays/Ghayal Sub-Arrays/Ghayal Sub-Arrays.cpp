// Ghayal Sub-Arrays.cpp : Defines the entry point for the console application.
//url:https://www.codechef.com/ASNE2016/problems/STUD3

#include <stdio.h>
#include <math.h>

bool isComp[1000001] = { false };

void SOE(long N)
{
	long i, j;
	isComp[0] = isComp[1] = false;
	isComp[2] = false;
	for (i = 2;i <= N;)
	{
		for (j = 2 * i;j <= N;j += i)
			isComp[j] = true;
		i++;
		while (isComp[i])
		{
			i++;
		}
	}
}

long arr[1000000];

int main()
{
	long N, i, tmp, j;
	long long X, ans = 0, sum = 0;
	scanf("%ld%lld", &N, &X);

	SOE(1000000);

	for (i = 0;i < N;i++)
	{
		scanf("%ld", &tmp);
		if (!isComp[tmp])
		{
			arr[i] = tmp;
		}
	}


	i = j = 0;

	while (i < N)
	{
		if (sum + arr[i] <= X)
		{
			sum += arr[i];
			ans += i - j + 1;
			i++;
		}
		else if (arr[i] > X)
		{
			i++;
			j = i;
			sum = 0;
		}
		else
		{
			sum += arr[i];
			while (sum > X)
			{
				sum -= arr[j];
				j++;
			}
			ans += i - j + 1;
			i++;
		}
	}
	printf("%lld", ans);

	return 0;
}

