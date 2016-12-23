// Gemstones.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int N, arr[26] = { 0 }, i, j;
	char str[101];
	scanf("%d", &N);
	for (i = 1;i <= N;i++)
	{
		scanf("%s", str);
		j = 0;
		while (str[j] != '\0')
		{
			arr[str[j] - 'a']++;
			j++;
		}
		for (j = 0; j < 26;j++)
		{
			if (arr[j] >= i)
			{
				arr[j] = i;
			}
			else
			{
				arr[j] = 0;
			}
		}
	}
	j = 0;
	for (i = 0;i < 26;i++)
	{
		if (arr[i] == N)
		{
			j++;
		}
	}
	printf("%d\n", j);
	return 0;
}

