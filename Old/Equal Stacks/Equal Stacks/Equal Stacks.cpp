// Equal Stacks.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/june-world-codesprint/challenges/equal-stacks

#include <stdio.h>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


void reverse(long ip[], long n)
{
	long i, tmp;
	n--;
	while (i <= n)
	{
		tmp = ip[i];
		ip[i] = ip[n];
		ip[n] = tmp;
		i++;
		n--;
	}
}




vector<long> a1(100002), a2(100002), a3(100002);
int main()
{
	
}

