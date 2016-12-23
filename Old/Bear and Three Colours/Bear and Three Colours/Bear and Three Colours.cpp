// Bear and Three Colours.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/DEC16/problems/THREECOL

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
#include <climits>
#include <unordered_map>

using namespace std;



void rowTransform(int N, int r1, int r2)
{
	int i;
	for (i = 1;i <= N;i++)
	{
		
		cout << r1 << " ";
		cout << i << " ";
		cout << r2 << " ";
		cout << i << "\n";
	}
}





void colTransform(int N, int c1, int c2)
{
	int i;
	for (i = 1;i <= N;i++)
	{
		cout << i << " ";
		cout << c1 << " ";
		cout << i << " ";
		cout << c2 << "\n";
	}
}







int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	/*long T, lp;
	long long ans;
	cin >> T;
	for (lp = 1;lp <= T;lp++)
	{
	cout << "Case #" << lp << ": " << ans << "\n";
	}*/

	int N, i, j;
	cin >> N;
	//cout << N*N / 2 << "\n";
	//int count = 1;
	switch (N)
	{
	case 2:
		cout << "4\n";
		colTransform(2, 1, 2);
		rowTransform(2, 1, 2);
		break;
	case 4:
		cout << "56\n";
		colTransform(4, 1, 2);
		colTransform(4, 3, 4);
		rowTransform(4, 1, 2);
		rowTransform(4, 3, 4);

		colTransform(4, 2, 3);
		colTransform(4, 3, 4);
		colTransform(4, 2, 3);
		colTransform(4, 1, 2);
		colTransform(4, 3, 4);
		rowTransform(4, 2, 3);
		rowTransform(4, 3, 4);
		rowTransform(4, 2, 3);
		rowTransform(4, 1, 2);
		rowTransform(4, 3, 4);
		break;
	case 5:
		cout << (21 * 5 + 14 * 4) << "\n";
		colTransform(4, 1, 2);
		colTransform(4, 3, 4);
		rowTransform(4, 1, 2);
		rowTransform(4, 3, 4);

		colTransform(4, 2, 3);
		colTransform(4, 3, 4);
		colTransform(4, 2, 3);
		colTransform(4, 1, 2);
		colTransform(4, 3, 4);
		rowTransform(4, 2, 3);
		rowTransform(4, 3, 4);
		rowTransform(4, 2, 3);
		rowTransform(4, 1, 2);
		rowTransform(4, 3, 4);//4x4

		colTransform(4, 4, 5);
		colTransform(4, 3, 4);
		colTransform(4, 2, 3);
		colTransform(4, 3, 4);
		colTransform(4, 2, 3);
		colTransform(4, 1, 2);
		colTransform(4, 3, 4);//4x5 abca

		rowTransform(5, 1, 2);
		rowTransform(5, 3, 4);
		rowTransform(5, 2, 3);
		rowTransform(5, 3, 4);
		rowTransform(5, 2, 3);
		rowTransform(5, 1, 2);
		rowTransform(5, 3, 4);//4x5 aaaa

		rowTransform(5, 4, 5);
		rowTransform(5, 3, 4);
		rowTransform(5, 2, 3);
		rowTransform(5, 3, 4);
		rowTransform(5, 2, 3);
		rowTransform(5, 1, 2);
		rowTransform(5, 3, 4);//5x5 abcab

		colTransform(5, 1, 2);
		colTransform(5, 3, 4);
		colTransform(5, 2, 3);
		colTransform(5, 3, 4);
		colTransform(5, 2, 3);
		colTransform(5, 1, 2);
		colTransform(5, 3, 4);//5x5 


		break;
	case 8:
		cout << (54 * 8) << "\n";
		//2x2
		colTransform(8, 1, 2);
		colTransform(8, 3, 4);
		colTransform(8, 5, 6);
		colTransform(8, 7, 8);
		rowTransform(8, 1, 2);
		rowTransform(8, 3, 4);
		rowTransform(8, 5, 6);
		rowTransform(8, 7, 8);
		//4x4
		colTransform(8, 2, 3);
		colTransform(8, 3, 4);
		colTransform(8, 2, 3);
		colTransform(8, 1, 2);
		colTransform(8, 3, 4);
		colTransform(8, 2+4, 3+4);
		colTransform(8, 3+4, 4+4);
		colTransform(8, 2+4, 3+4);
		colTransform(8, 1+4, 2+4);
		colTransform(8, 3+4, 4+4);
		rowTransform(8, 2, 3);
		rowTransform(8, 3, 4);
		rowTransform(8, 2, 3);
		rowTransform(8, 1, 2);
		rowTransform(8, 3, 4);
		rowTransform(8, 2 + 4, 3 + 4);
		rowTransform(8, 3 + 4, 4 + 4);
		rowTransform(8, 2 + 4, 3 + 4);
		rowTransform(8, 1 + 4, 2 + 4);
		rowTransform(8, 3 + 4, 4 + 4);
		//8x8
		colTransform(8, 4, 5);
		colTransform(8, 3, 4);
		colTransform(8, 5, 6);
		
		colTransform(8, 2, 3);
		colTransform(8, 3, 4);
		colTransform(8, 2, 3);
		colTransform(8, 1, 2);
		colTransform(8, 3, 4);
		colTransform(8, 2+4, 3+4);
		colTransform(8, 3+4, 4+4);
		colTransform(8, 2+4, 3+4);
		colTransform(8, 1+4, 2+4);
		colTransform(8, 3+4, 4+4);

		rowTransform(8, 4, 5);
		rowTransform(8, 3, 4);
		rowTransform(8, 5, 6);

		rowTransform(8, 2, 3);
		rowTransform(8, 3, 4);
		rowTransform(8, 2, 3);
		rowTransform(8, 1, 2);
		rowTransform(8, 3, 4);
		rowTransform(8, 2+4, 3+4);
		rowTransform(8, 3+4, 4+4);
		rowTransform(8, 2+4, 3+4);
		rowTransform(8, 1+4, 2+4);
		rowTransform(8, 3+4, 4+4);


		break;
	default:
		cout << N*N / 2 << "\n";
		for (i = 1;i <= N;i++)
		{
			for (j = 1;j <= N;j += 2)
			{
				cout << i << " " << j << " ";
				cout << i << " " << (j + 1);
				//cout << " " << count++;
				cout << "\n";
			}
		}
		break;
	}
	
	return 0;
}

