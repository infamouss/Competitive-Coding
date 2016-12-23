// Paying up.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


void willRobbed(int money[], int num, bool* willPay, int toPay, int sumTotal)
{
	if (!*willPay && num > 0)
	{
		num--;
		if (sumTotal + money[num] == toPay)
		{
			*willPay = true;
		}
		else if (sumTotal < toPay)
		{
			willRobbed(money, num, willPay, toPay, sumTotal);
			willRobbed(money, num, willPay, toPay, sumTotal + money[num]);
		}
	}
}

int main()
{
	int T, money[20], num, toPay, i;
	bool willPay;
	scanf("%d", &T);
	while (T--)
	{
		willPay = false;
		scanf("%d%d", &num, &toPay);
		for (i = 0;i < num;i++)
		{
			scanf("%d", &money[i]);
		}
		willRobbed(money, num, &willPay, toPay, 0);
		printf("%s\n", (willPay) ? "Yes" : "No");
	}
    return 0;
}

