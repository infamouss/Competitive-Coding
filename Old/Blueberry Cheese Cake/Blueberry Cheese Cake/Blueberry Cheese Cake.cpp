// Blueberry Cheese Cake.cpp : Defines the entry point for the console application.
//


#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <string>

using namespace std;



int main()
{
	long N, B, i, ans = 0, ind=0;
	long long total = 0;
	scanf("%ld%ld", &N, &B);
	vector<long> studs(N);
	for (i = 0;i < N;i++)
	{
		scanf("%ld", &studs[i]);
		total += studs[i];
	}
		
	
	printf("%ld\n", (long)ceil((float)total/B));



	return 0;
}

