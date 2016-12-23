// Three Way Communications.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, x1, x2, x3, y1, y2, y3, ans;
	long R;
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%ld%d%d", &R, &x1, &y1);
		scanf("%d%d", &x2, &y2);
		scanf("%d%d", &x3, &y3);
		R *= R;
		if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) <= R)
			ans++;
		if (((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)) <= R)
			ans++;
		if (((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3)) <= R)
			ans++;
		printf("%s\n", (ans > 1) ? "yes" : "no");
	}
    return 0;
}

