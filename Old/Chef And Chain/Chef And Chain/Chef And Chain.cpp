#include<stdio.h>
#include<string.h>


int main()
{
	char a[100001], c, d;
	int t, i, j, ans, ep, em, op, om;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%s", a);
		j = 0;
		ep = em = op = om = 0;
		while (a[j]!='\0')
		{
			if (j % 2 == 0)
			{
				if (a[j] == '+')
				{
					ep++;
				}
				else
				{
					em++;
				}
			}
			else
			{
				if (a[j] == '-')
				{
					om++;
				}
				else
				{
					op++;
				}
			}
			j++;
		}
		c = ep + om;
		d = em + op;
		if (c < d)
		{
			printf("%d\n", c);
		}
		else
		{
			printf("%d\n", d);
		}

	}
	return 0;
}