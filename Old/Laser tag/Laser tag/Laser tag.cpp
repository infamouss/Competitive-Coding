#include<stdio.h>

int main()
{
	int t, x1, y1, r1, x2, y2, r2, d;
	scanf("%d", &t);
	while (t)
	{
		scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
		d = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
		if (r1 == 0)
		{
			if (r2 == 0)
			{
				if (x1 == x2 && y1 == y2)
				{
					printf("INFI\n");
				}
				else
				{
					printf("1\n");
				}
			}
			else
			{
				if (d > r2*r2)
				{
					printf("2\n");
				}
				else if (d < r2*r2)
				{
					printf("0\n");
				}
				else
				{
					printf("1\n");
				}
			}
		}
		else if (r2 == 0)
		{
			if (r1 == 0)
			{
				if (x1 == x2 && y1 == y2)
				{
					printf("INFI\n");
				}
				else
				{
					printf("1\n");
				}
			}
			else
			{
				if (d > r1*r1)
				{
					printf("2\n");
				}
				else if (d < r1*r1)
				{
					printf("0\n");
				}
				else
				{
					printf("1\n");
				}
			}
		}
		else
		{
			if (d == 0)
			{
				if (r1 == r2)
				{
					printf("INFI\n");
				}
				else
				{
					printf("0\n");
				}
			}
			else
			{
				if (d>(r1 + r2)*(r1 + r2))
				{
					printf("4\n");
				}
				else if (d == (r1 + r2)*(r1 + r2))
				{
					printf("3\n");
				}
				else
				{
					if (d > (r1 - r2)*(r1 - r2))
					{
						printf("2\n");
					}
					else if (d == (r1 - r2)*(r1 - r2))
					{
						printf("1\n");
					}
					else
					{
						printf("0\n");
					}
				}
			}
		}
		t--;
	}
	return 0;
}