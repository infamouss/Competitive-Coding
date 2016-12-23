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

	long T, N, i;
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<long long> arr(N);
		for (i = 0;i < N;i++)
		{

			cin >> arr[i];


		}

		sort(arr.begin(), arr.end());

		if (N == 1)
		{
			cout << "yes\n";
		}
		else if (arr[0] == 0 && arr[N - 1] == 0)//all 0
		{
			cout << "yes\n";
		}
		//else if (arr[0] == 1 && arr[N - 1] == 1)
		//{
		//	cout << "yes\n";
		//}
		else
		{

			
			if (arr[0] < 0)//-ve present
			{


				if (arr[N - 1] == 0)//only -ve and 0
				{
					if (arr[1] != 0)
					{
						cout << "no\n";
					}
					else
					{
						cout << "yes\n";
					}
				}
				else if(arr[N-1]<0)//only -ve
				{
					cout << "no\n";
				}
				else//everything present
				{
					//(-1)(-)(0)(+)(1)(1)


					if (arr[0] < 0 && (arr[1] == 0 || arr[1] == 1) && (arr[N - 1] == 0 || arr[N - 1] == 1))
					{
						cout << "yes\n";
					}



					else if (arr[0] == -1 && arr[N - 1] == 1)
					{
						cout << "yes\n";
					}
					else
					{
						cout << "no\n";
					}


				}
			}
			else//-ve absent
			{
				if (arr[N - 1] == 0)//all 0
				{
					cout << "yes\n";
				}
				else if (arr[N - 2] == 0 || arr[N - 2] == 1)
				{
					cout << "yes\n";
				}

				else
				{
					cout << "no\n";
				}
			}



		}






	}



	return 0;
}