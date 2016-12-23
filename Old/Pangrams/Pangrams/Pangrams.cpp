// Pangrams.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	char str[1001];
	int pan[26] = { 0 }, i, count = 0;
	gets_s(str);
	while (str[i] != '\0'&&count < 26)
	{
		if (str[i] >= 'a'&&str[i] <= 'z')
		{
			if (pan[str[i] - 'a'] == 0)
			{
				count++;
			}
			pan[str[i] - 'a']++;
		}
		else if (str[i] >= 'A'&&str[i] <= 'Z')
		{
			if (pan[str[i] - 'A'] == 0)
			{
				count++;
			}
			pan[str[i] - 'A']++;
		}
		i++;
	}
	printf("%spanagram\n", (count != 26) ? "not " : "");
	return 0;
}

