// Counting Strings.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/COOK74/problems/TACNTSTR

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
#define mod 1000000007




long long pwr(long long a, long long b)
{
	long long ans = 1, mul = a;

	while (b>0)
	{
		if (b % 2 == 1)
			ans = (ans*mul) % mod;
		b /= 2;
		mul = mul*mul % mod;
	}
	return ans;

}



long long ge(string& s, long long start, long long end)
{
	long long ans;

	if (start == end)
	{
		ans = ('Z' - s[start]) + 1;
	}
	else if (start + 1 == end)
	{
		ans = (26 * ('Z' - s[end]) + ('Z' - s[start]) + 1) % mod;
		//ans = (1 + ('Z' - s[start])*('Z' - s[end])) % mod;

	}
	else
	{
		ans = ((('Z' - s[end])*pwr(26, end - start)) % mod + ge(s, start, end - 1) % mod) % mod;
	}
	return ans;
}


long long eg(string& s, long long start, long long end)
{
	long long ans;


	if (start == end)
	{
		ans = ('Z' - s[start]) + 1;
	}
	else if (start + 1 == end)
	{
		ans = (26 * ('Z' - s[start]) + ('Z' - s[end]) + 1) % mod;
		//ans = (1 + ('Z' - s[start])*('Z' - s[end])) % mod;
	}
	else
	{
		ans = ((('Z' - s[start])*pwr(26, end - start)) % mod + eg(s, start + 1, end) % mod) % mod;
	}




	return ans;
}





long long solve(string& s, long long start, long long end)
{
	long long ans;
	if (start == end)
	{
		ans = 'Z' - s[start];
	}
	else if (start + 1 == end)
	{
		ans = ('Z' - s[start])*('Z' - s[end]) + ('Z' - s[start]) + ('Z' - s[end]);
	}
	else
	{

		ans = ( (('Z' - s[start])*('Z' - s[end])*pwr(26,end-start-1))%mod +solve(s,start+1,end-1)%mod+  
			(ge(s,start+1,end-1)*('Z'-s[start])*(1))%mod +(eg(s,start+1,end-1)*(1)*('Z'-s[end]))%mod) % mod;

	}
	return ans;
}



int main()
{
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);


	

	string s;
	long long i, j, ans = 0, len;

	cin >> s;

	len = s.length();


	long long** a;
	a = (long long**)malloc(sizeof(long long*)*len);
	
	for (i = 0;i < len;i++)
	{
		a[i] = (long long*)malloc(sizeof(long long)*len);
	}

	ans = solve(s, 0, len - 1);

	cout << ans << "\n";








	return 0;
}

