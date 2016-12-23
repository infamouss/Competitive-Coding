// Chef and the Wildcard Matching.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, i, flag;
	char a[11], b[11];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s%s", a, b);
		i = flag = 0;
		while (a[i] != '\0'&&flag == 0)
		{
			if (a[i] != '?'&&b[i] != '?')
			{
				if (a[i] != b[i])
				{
					flag = 1;
				}
			}
			i++;
		}
		printf("%s\n", (flag == 0) ? "Yes" : "No");
	}
    return 0;
}

