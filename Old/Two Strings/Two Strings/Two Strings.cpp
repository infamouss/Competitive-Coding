// Two Strings.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, flag;
	long i;
	char str1[100001], str2[100001];
	scanf("%d", &T);
	while (T--)
	{
		long arr[26] = { 0 };
		flag = 0;
		scanf("%s%s", str1, str2);
		i = 0;
		while (str1[i] != '\0')
		{
			arr[str1[i] - 'a']++;
			i++;
		}
		i = 0;
		while (str2[i] != '\0'&&flag == 0)
		{
			if (arr[str2[i] - 'a'] != 0)
			{
				flag = 1;
			}
			i++;
		}
		printf("%s\n", (flag == 0) ? "NO" : "YES");
	}
	return 0;
}

