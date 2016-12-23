// The Lead Game.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int n, P1, P2, winner, lead, tmp, i, P1tot, P2tot;
	scanf("%d", &n);
	scanf("%d%d", &P1tot, &P2tot);
	if (P1tot < P2tot)
	{
		winner = 2;
		lead = P2tot - P1tot;
	}
	else
	{
		winner = 1;
		lead = P1tot - P2tot;
	}
	for (i = 1;i < n;i++)
	{
		scanf("%d%d", &P1, &P2);
		P1tot += P1;
		P2tot += P2;
		if (P1 < P2)
		{
			tmp = P2tot - P1tot;
			if (tmp > lead)
			{
				lead = tmp;
				winner = 2;
			}
		}
		else
		{
			tmp = P1tot - P2tot;
			if (tmp > lead)
			{
				lead = tmp;
				winner = 1;
			}
		}
	}
	printf("%d %d", winner, lead);

    return 0;
}

