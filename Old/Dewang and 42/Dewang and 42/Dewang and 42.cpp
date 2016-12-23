// Dewang and 42.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

int main()
{
	int T;
	long i, count4, ans;
	char str[1000001];

	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str);
		i = count4 = ans = 0;
		
		while (str[i] != '\0')
		{
			if (str[i] == '4')
			{
				count4++;
			}
			else if (str[i] == '2')
			{
				ans += count4;
			}
			i++;
		}

		printf("%ld\n", ans);

	}
	return 0;
}

