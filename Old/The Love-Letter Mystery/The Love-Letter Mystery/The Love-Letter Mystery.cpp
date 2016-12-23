// The Love-Letter Mystery.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
	int T, ans, i, len;
	char str[10001];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str);
		i = 0;
		ans = 0;
		len = strlen(str);
		while (i < len / 2)
		{
			ans += abs(str[i] - str[len - 1 - i]);
			i++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

