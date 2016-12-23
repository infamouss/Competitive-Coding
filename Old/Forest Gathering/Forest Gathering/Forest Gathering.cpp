// Forest Gathering.cpp : Defines the entry polong for the console application.
// url : https://www.codechef.com/MAY16/problems/FORESTGA

#include <stdio.h>


typedef struct node_tag
{
	long long height, rate, months;
} node;





void insertHeap(node current, long low, long high, node a[])
{
	long large, done = 0;
	large = 2 * low + 1;
	while (large <= high && !done)
	{
		if (large < high && a[large].months < a[large + 1].months)
		{
			large++;
		}
		if (current.months > a[large].months)
		{
			done = 1;
		}
		else
		{
			a[low] = a[large];
			low = large;
			large = 2 * low + 1;
		}
	}
	a[low] = current;
}

void buildHeap(node a[], long n)
{
	long low;
	for (low = n / 2 - 1; low >= 0; low--)
	{
		insertHeap(a[low], low, n - 1, a);
	}
}

void heapSort(node a[], long n)
{
	long lu;
	node current;
	buildHeap(a, n);
	for (lu = n - 1; lu >= 1; lu--)
	{
		current = a[lu];
		a[lu] = a[0];
		insertHeap(current, 0, lu - 1, a);
	}
}



node tree[100000];
long main()
{

	long N, i;
	long long W, L, totRate = 0, ans;
	
	scanf("%ld%lld%lld", &N, &W, &L);
	for (i = 0;i < N;i++)
	{
		scanf("%lld%lld", &tree[i].height, &tree[i].rate);
		tree[i].months = (L - tree[i].height + tree[i].rate - 1) / tree[i].rate;
	}

	heapSort(tree, N);

	/*for (i = 0;i < N;i++)
	{
		printf("%lld %lld %lld\n", tree[i].height, tree[i].rate, tree[i].months);
	}*/


	i = 0;
	while (i < N && tree[i].months <= 0)
	{
		totRate += tree[i].rate;
		W -= tree[i].height;
		i++;
	}

	if (W <= 0)
	{
		ans = 0;
	}
	else
	{

















	}





	



































	return 0;
}

