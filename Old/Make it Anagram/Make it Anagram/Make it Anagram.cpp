// Make it Anagram.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>

int main()
{
	char str1[10001], str2[10001];
	int i, ans = 0, arr[26] = { 0 };
	scanf("%s%s", str1, str2);
	i = 0;
	while (str1[i] != '\0')
	{
		arr[str1[i] - 'a']++;
		i++;
	}
	i = 0;
	while (str2[i] != '\0')
	{
		arr[str2[i] - 'a']--;
		i++;
	}
	for (i = 0;i < 26;i++)
	{
		ans += abs(arr[i]);
	}
	printf("%d\n", ans);
	return 0;
}

