// Alternating Characters.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	long i, j, toDel;
	char str[100001];
	scanf("%d", &T);
	while (T--)
	{
		i = 1;
		j = 0;
		toDel = 0;
		scanf("%s", str);
		while (str[i] != '\0')
		{
			if (str[i] == str[j])
			{
				toDel++;
			}
			else
			{
				j = i;
			}
			i++;
		}
		printf("%ld\n", toDel);
	}
	return 0;
}

