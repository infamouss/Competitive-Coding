// Gravity Guy.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	long T, i, j, ans;
	int willCross, lane;
	char str[2][200001];
	scanf("%ld", &T);
	while (T--)
	{
		scanf("%s%s", str[0], str[1]);
		i = 0;
		ans = 0;
		willCross = 1;
		lane = -1;
		while (str[0][i] != '\0' && lane == -1)
		{
			if (str[0][i] == '#')
			{
				lane = 1;
				i--;
			}
			else if (str[1][i] == '#')
			{
				lane = 0;
				i--;
			}
			i++;
		}
		while (str[0][i] != '\0' && willCross)
		{
			if (str[0][i] == '#' && str[1][i] == '#')
			{
				willCross = 0;
			}
			else if (str[lane][i] == '#')
			{
				lane = (lane + 1) % 2;
				ans++;
			}
			i++;
		}
		if (willCross)
		{
			printf("Yes\n%ld\n", ans);
		}
		else
		{
			printf("No\n");
		}
	}
    return 0;
}

