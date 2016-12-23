// Holes in the text.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, i, ans;
	char ip[101];
	scanf("%d", &T);
	while (T--)
	{
		i = ans = 0;
		scanf("%s", ip);
		while (ip[i] != '\0')
		{
			switch (ip[i])
			{
			case 'A':
				ans++;
				break;
			case 'B':
				ans += 2;
				break;
			case 'D':
				ans++;
				break;
			case 'O':
				ans++;
				break;
			case 'P':
				ans++;
				break;
			case 'Q':
				ans++;
				break;
			case 'R':
				ans++;
				break;
			}
			i++;
		}
		printf("%d\n", ans);
	}



    return 0;
}

