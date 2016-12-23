#include <iostream>
#include <string>

using namespace std;

long long nCr(int n, int r)
{
	long long ans = 1;
	int i;
	r = (r > n / 2) ? n - r : r;
	for (i = 1;i <= r;i++)
	{
		ans = ans*(n + 1 - i) / i;
	}
	return ans;
}


int main()
{
	printf("%lld\n", nCr(20, 16));


	return 0;
}