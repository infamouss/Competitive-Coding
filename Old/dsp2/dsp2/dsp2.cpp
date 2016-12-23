/*DSP Assignment-2
Author - Bala Raveen Nadar
Roll No. - BT13CSE055
*/

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

	vector<double> x1(100, 0), x2(100, 0), y(100, 0);
	int i, j, m, n, n1, n2, min_n, len_linear, len_circular;
	cout << "Enter size of first input x1[n1]: ";
	cin >> n1;
	cout << "\nEnter size of second input x2[n2]: ";
	cin >> n2;
	for (i = 0;i<100;i++)
	{
		x1[i] = 0;
		x2[i] = 0;
	}
	cout << "\nEnter first input x1[n1]:\n";
	for (i = 0;i<n1;i++)
	{
		cin >> x1[i];
	}
	cout << "\nEnter second input x2[n2]:\n";
	for (i = 0;i<n2;i++)
	{
		cin >> x2[i];
	}
	if (n1 <= n2)
	{
		min_n = n1;
	}
	else
	{
		min_n = n2;
	}
	len_linear = n1 + n2 - 1;
	for (n = 0;n<len_linear;n++)
	{
		y[n] = 0;
		for (m = 0;m<min_n;m++)
		{
			i = m;
			j = n - m;
			if (i >= 0 && j >= 0)
			{
				if (min_n == n1)
				{
					y[n] += x1[i] * x2[j];
				}
				else
				{
					y[n] += x2[i] * x1[j];
				}
			}
		}
	}
	cout << "\nLinear convolution output\n";
	for (i = 0;i<len_linear;i++)
	{
		cout << y[i] << " ";
	}
	len_circular = max(n1, n2);
	for (n = 0;n<len_circular;n++)
	{
		y[n] = 0;
		for (m = 0;m<len_circular;m++)
		{
			i = m;
			j = (n - m) % len_circular;
			if (j<0)
			{
				j = j + len_circular;
			}
			y[n] += x1[i] * x2[j];
		}
	}
	cout << "\nCircular convolution output:\n";
	for (i = 0;i<len_circular;i++)
		cout << y[i] << " ";
	for (n = 0;n<len_linear;n++)
	{
		y[n] = 0;
		for (m = 0;m<len_linear;m++)
		{
			i = m;
			j = (n - m) % len_linear;
			if (j<0)
				j = j + len_linear;
			y[n] += x1[i] * x2[j];
		}
	}
	cout << "\nCircular convolution(expanded to linear convolution length) output:\n";
	for (i = 0;i<len_linear;i++)
		cout << y[i] << " ";
	cout << "\n";
	return 0;
}
