// Counter Culture.cpp : Defines the entry point for the console application.
//

#include <stdio.h>




int flip(int n)
{
	int ans = 0;
	while (n != 0)
	{
		ans = 10 * ans + n % 10;
		n = n / 10;
	}
	return ans;
}




















int main()
{
	int T, i, num, count, tmp, tmp1;
	scanf("%d", &T);
	for (i = 1; i <= T; i++)
	{
		count = 0;
		scanf("%d", &num);



		tmp = num;
		while (tmp != 0)
		{
			tmp1 = flip(tmp);
			if (tmp1 < tmp && tmp1 >= 1 && tmp % 10 != 0)
			{
				tmp = tmp1;
			}
			else
			{
				tmp--;
			}
			count++;
		}



		/*tmp = 0;
		while (tmp != num)
		{
			tmp1 = flip(tmp);
			if (tmp1 > tmp && tmp1 <= num)
			{
				tmp = tmp1;
			}
			else
			{
				tmp++;
			}
			count++;
		}*/



		printf("Case #%d: %d\n", i, count);




	}






	return 0;
}

