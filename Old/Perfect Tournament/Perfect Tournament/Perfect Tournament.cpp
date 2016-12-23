// Perfect Tournament.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<math.h>
#include<stdint.h>


int main()
{
	int t,flag=0;
	unsigned long long num;
	float ans;
	scanf("%d", &t);
	while (t)
	{
		scanf("%llu", &num);
		
		flag = 0;


		
		while (num != 1 && flag == 0)
		{
			if (num % 2 == 1)
			{
				flag = 1;
			}
			num = num / 2;
		}

		if (flag == 0)
		{
			printf("Perfect\n");
		}
		else
		{
			printf("Imperfect\n");
		}

		
		t--;
	}
	return 0;
}