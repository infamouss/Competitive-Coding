// Chef and Coins Game.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/JUNE16/CHCOINSG

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

int main()
{
	int T;
	long long N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		//cout << (N % 6 == 0) ? "Misha" : "Chef";
		printf("%s", (N % 6 == 0) ? "Misha" : "Chef");
		cout << endl;
	}




	return 0;
}

