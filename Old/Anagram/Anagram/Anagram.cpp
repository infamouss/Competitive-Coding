// Anagram.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>


int main()
{
	int T, len, arr[26] = { 0 }, i, mid, ans;
	char str[10001];
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%s", str);
		len = strlen(str);
		if (len % 2 == 1)
		{
			printf("-1\n");
		}
		else
		{
			mid = len / 2;
			for (i = 0;i < mid;i++)
			{
				arr[str[i] - 'a']--;
			}
			for (;i < len;i++)
			{
				arr[str[i] - 'a']++;
			}
			for (i = 0;i < 26;i++)
			{
				if (arr[i] > 0)
				{
					ans += arr[i];
				}
				arr[i] = 0;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}

