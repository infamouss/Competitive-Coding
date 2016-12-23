// C. BFFsC.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, N, arr[1001] = { 0 }, ans, length;

	scanf("%d", &T);
	for (int i = 1;i <= T;i++)
	{
		scanf("%d", &N);
		for (int j = 1;j <= N;j++)
		{
			scanf("%d", &arr[j]);
		}

		ans = 0;
		
		for (int j = 1;j <= N && ans < N;j++)
		{
			int isVisited[1001] = { 0 };
			length = 1;
			int index = j;
			isVisited[index] = 1;
			/*do
			{
				isVisited[index] = 1;
				index = arr[index];
				if (isVisited[index] == 0)
					length++;
			} while (isVisited[index] == 0);*/
			index = arr[index];
			while (isVisited[index] == 0)
			{
				length++;
				isVisited[index] = 1;
				index = arr[index];
			}





			if (index == j && length > ans)
			{
				ans = length;
			}




		}

		
		printf("%d\n", ans);



	}




	return 0;
}

