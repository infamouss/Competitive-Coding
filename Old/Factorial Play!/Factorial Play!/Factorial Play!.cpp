// Factorial Play!.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int t, index, num, tmp, arr[100], i, j, num1;
	//long ans;
	scanf("%d", &t);
	while (t)
	{
		
		index = -1;
		scanf("%d", &num);
		num1 = num;
		while (num != 0)
		{
			tmp = num % 10;

			switch (tmp)
			{
			case 2:
				index++;
				arr[index] = 2;				
				break;
			case 3:
				index++;
				arr[index] = 3;
				break;
			case 4:
				index++;
				arr[index] = 3;
				index++;
				arr[index] = 2;
				index++;
				arr[index] = 2;
				break;
			case 5:
				index++;
				arr[index] = 5;
				break;
			case 6:
				index++;
				arr[index] = 5;
				index++;
				arr[index] = 3;
				break;
			case 7:
				index++;
				arr[index] = 7;
				break;
			case 8:
				index++;
				arr[index] = 7;
				index++;
				arr[index] = 2;
				index++;
				arr[index] = 2;
				index++;
				arr[index] = 2;
				break;
			case 9:
				index++;
				arr[index] = 7;
				index++;
				arr[index] = 3;
				index++;
				arr[index] = 3;
				index++;
				arr[index] = 2;				
				break;
			}
			

			



			num = num / 10;
		}


		
		if (index == -1)
		{
			printf("%d", num1);
		}
		else
		{
			for (i = 0; i < index; i++)
			{
				for (j = i + 1; j <= index; j++)
				{
					if (arr[i] < arr[j])
					{
						tmp = arr[i];
						arr[i] = arr[j];
						arr[j] = tmp;
					}
				}
			}
			/*ans = 0;
			for (i = 0; i <= index; i++)
			{
				ans = 10 * ans + arr[i];
			}*/
			for (i = 0; i <= index; i++)
				printf("%d", arr[i]);
			/*if (ans > num1)
			{
				printf("%d", ans);
			}
			else
			{
				printf("%d", num1);
			}*/
		}
			

		printf("\n");
		t--;
	}
	return 0;
}

