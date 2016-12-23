// Amazing Experiment.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/APRIL16/problems/AMAEXPER

#include <stdio.h>

long long a[100000000];

int main()
{
	int T, w, tmp;
	long N, i, u, v;



	//for subtask 1

	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld",&N);
		w = 0;
		for (i = 0;i < N - 1;i++)
		{
			scanf("%ld%ld%d", &u, &v, &tmp);
			if (tmp > w)
			{
				w = tmp;
			}
		}
		printf("%d\n", w);
		for (i = 1;i < N;i++)
		{
			printf("0\n");
		}
	}






	return 0;
}

