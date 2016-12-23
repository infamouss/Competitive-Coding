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

#define N 100000
#define MAX 1000000
typedef long long int lli;
typedef int ll;
using namespace std;
ll ansglobal;
map<lli, ll> mp;

int main()
{
	ll t;
	scanf("%d", &t);
	while (t--)
	{
		ll n, k, i;
		scanf("%d %d", &n, &k);
		lli val;
		for (i = 0;i<n;i++)
		{
			scanf("%lld", &val);
			if (mp.find(val) == mp.end())
			{
				mp[val] = 0;
			}
			mp[val]++;
		}
		vector<ll> v;
		for (std::map<lli, ll>::iterator it = mp.begin(); it != mp.end(); ++it)
		{
			n -= (it->second / k)*k;
			it->second %= k;
			if (it->second != 0)
			{
				v.push_back(it->second);
			}
		}
		mp.clear();
		ll gone = 0, siz = v.size();
		map<ll, ll> prev;
		prev[k - v[0]] = 0;
		for (i = 1;i<siz;i++)
		{
			//printf("iteration for i=%d\n",i);
			map<ll, ll> mpp;
			gone += v[i - 1];
			for (std::map<ll, ll>::iterator it = prev.begin(); it != prev.end(); ++it)
			{
				//printf("called for i=%d todrop=%d possible=%d\n",i,it->first,n-gone);
				//call1(i,it->first,n-gone,v,k);
				ll pos = i;
				ll todrop = it->first;
				ll possibletodrop = n - gone;
				if (todrop + k - v[pos] <= possibletodrop - v[pos])
				{
					if (mpp.find(todrop + k - v[pos]) == mpp.end())
					{
						mpp[todrop + k - v[pos]] = MAX;
					}

					mpp[todrop + k - v[pos]] = min(mpp[todrop + k - v[pos]], prev[todrop]);
				}

				// tale i not as base
				//call(i+1,todrop-v[i],possible-v[i],v,ans+v[i],siz,k);
				if (todrop >= v[pos])
				{
					if (mpp.find(todrop - v[pos]) == mpp.end())
					{
						mpp[todrop - v[pos]] = MAX;
					}
					mpp[todrop - v[pos]] = min(mpp[todrop - v[pos]], prev[todrop] + v[pos]);
					//printf("inn %d\n\n",mpp[pos][todrop-v[pos]]);
				}
			}
			prev = mpp;
		}
		printf("%d\n", prev[0]);
		prev.clear();
	}
	return 0;
}