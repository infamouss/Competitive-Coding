// Intervals and subarrays.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>

int good(int a[], int start, int end);

int ans;
int memo[100][100] = { 0 };



int main()
{
	int T;
	int arr[100], n, min;
	int i;


	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%d%d", &n, &min);
		for (i = 0;i < n;i++)
		{
			scanf("%d", &arr[i]);
		}
		ans = good(arr, 0, n - 1);
		printf("%d\n", ans);
	}



	return 0;
}



int good(int a[], int start, int end)
{
	int retval;
	int left,right;




	if (end - start == 1)
	{
		if (abs(a[start] - a[end]) == 1)
		{
			ans++;
		}
	}




	//for left







	//for right








	return retval;
}