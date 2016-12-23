#include<stdio.h>
#include<string.h>


int main()
{
	char input[20];
	int t, num, sA = 0, uSA = 0, watch[1001] = {0}, countWatch = 0, i, flag, tmp;
	scanf("%d", &t);
	while (t)
	{
		sA = 0;
		uSA = 0;
		countWatch = 0;
		scanf("%d", &num);
		scanf("%s", input);
		if (strcmp(input, "click") == 0)
		{
			scanf("%d", &tmp);
			flag = 0;
			for (i = 0; (i < countWatch) && (flag == 0); i++)
			{
				if (watch[i] == tmp)
				{
					watch[i] = watch[countWatch];
					watch[countWatch] = 0;
					countWatch--;
					flag = 1;
				}
			}
			if (flag == 0)
			{
				watch[i] = tmp;
				countWatch++;
			}
		}
		else if (strcmp(input, "select_all") == 0)
		{
			sA = 1;
			uSA = 0;
			for (i = 0; i < countWatch; i++)
			{
				watch[i] = 0;
			}
			countWatch = 0;
		}
		else if (strcmp(input, "unselect_all") == 0)
		{
			uSA = 1;
			sA = 0;
			for (i = 0; i < countWatch; i++)
			{
				watch[i] = 0;
			}
			countWatch = 0;
		}
		while (strcmp(input, "submit") != 0)
		{
			if (sA == 0 && uSA == 0)
			{
				printf("%d\n", countWatch);
			}
			else if (sA == 0 && uSA == 1)
			{
				printf("%d\n", countWatch);
			}
			else if (uSA == 0 && sA == 1)
			{
				printf("%d\n", num - (countWatch));
				
			}
			scanf("%s", input);
			if (strcmp(input, "click") == 0)
			{
				scanf("%d", &tmp);
				flag = 0;
				for (i = 0; (i < countWatch) && (flag == 0); i++)
				{
					if (watch[i] == tmp)
					{
						watch[i] = watch[countWatch];
						watch[countWatch] = 0;
						countWatch--;
						flag = 1;
					}
				}
				if (flag == 0)
				{
					watch[i] = tmp;
					countWatch++;
				}
			}
			else if (strcmp(input, "select_all") == 0)
			{
				sA = 1;
				uSA = 0;
				for (i = 0; i < countWatch; i++)
				{
					watch[i] = 0;
				}
				countWatch = 0;
			}
			else if (strcmp(input, "unselect_all") == 0)
			{
				uSA = 1;
				sA = 0;
				countWatch = 0;
				for (i = 0; i < countWatch; i++)
				{
					watch[i] = 0;
				}
				countWatch = 0;
			}	
		}
		printf("done\n");
		for (i = 0; i < countWatch; i++)
		{
			watch[i] = 0;
		}
		t--;
	}
	return 0;
}