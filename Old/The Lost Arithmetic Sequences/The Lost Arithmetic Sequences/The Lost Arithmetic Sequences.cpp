// The Lost Arithmetic Sequences.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/COOK74/problems/TAASEQ

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	long N, i;
	while (T--)
	{
		cin >> N;
		vector<long long> arr(N);
		for (i = 0;i < N;i++)
			cin >> arr[i];
		long long d;
		long index;
		long change = 0;



		if (N == 2)
		{
			cout << min(arr[0], arr[1]) << "\n";
		}
		else if (N == 3)
		{
			cout << min(arr[0], min(arr[1], arr[2]))<<"\n";
		}
		else
		{

			
			index = -1;
			if (arr[3] - arr[2] == arr[2] - arr[1] && arr[2] - arr[1] == arr[1] - arr[0])
			{
				d = arr[1] - arr[0];
				index = -1;
				change = 0;
			}
			//eleminate 0
			else if (arr[2] - arr[1] == arr[3] - arr[2] && arr[1] - arr[0] != arr[2] - arr[1])
			{
				index = 0;
				d = arr[2] - arr[1];
				change = 1;
			}

			//eleminate 1

			else if (arr[2] - arr[0] == arr[3] - arr[2] && arr[1] - arr[0] != arr[3] - arr[2])
			{
				index = 1;
				d = arr[2] - arr[0];
				change = 1;
			}

			//eleminate 2

			else if (arr[3] - arr[1] == arr[1] - arr[0] && arr[1] - arr[0] != arr[2] - arr[1])
			{
				index = 2;
				d = arr[3] - arr[1];
				change = 1;
			}
			else if ((arr[1] - arr[0] == arr[2] - arr[1]) && (arr[3] - arr[2] != arr[1] - arr[0]))
			{
				index = 3;d = arr[1] - arr[0];
			}
			else if (arr[3] - arr[2] != arr[2] - arr[1] && arr[2] - arr[1] != arr[1] - arr[0])
			{
				cout << "-1\n";
				continue;
			}
			if (index == 3)
			{
				i = 5;
				if (arr[5] - arr[3] != d)
				{
					change++;
				}
			}
			else
			{
				i = 4;
			}
			for (;i < N;i++)
			{
				if (arr[i] - arr[i - 1] != d)
				{
					index = i;
					change++;
					i++;
				}
			}
			if (change == 0)
			{
				cout << min(arr[0], arr[N - 1]) << "\n";
			}
			else if (change == 1)
				cout << arr[index] << "\n";
			else
				cout << "-1\n";
		}
	}
	return 0;
}

