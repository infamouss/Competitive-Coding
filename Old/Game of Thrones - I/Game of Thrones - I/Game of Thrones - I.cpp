// Game of Thrones - I.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	char str[100001];
	long i = 0;
	long pal[26] = { 0 };
	int flag = 0;
	scanf("%s", str);
	while (str[i] != '\0')
	{
		pal[str[i] - 'a']++;
		i++;
	}
	i = 25;
	while (i--&&flag < 2)
	{
		if (pal[i] % 2 == 1)
		{
			flag++;
		}
	}
	printf("%s", (flag < 2) ? "YES" : "NO");
	return 0;
}

