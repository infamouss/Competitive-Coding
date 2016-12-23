// B. Close Match.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, i, j, aWin;
	char A[19], B[19], ansA[19], ansB[19];
	
	scanf("%d", &T);

	for (i = 1;i <= T;i++)
	{
		scanf("%s%s", A, B);


		j = 0;
		while (A[j] != '\0')
		{
			while (A[j] != '\0'&&A[j] == '?'&&B[j] == '?')
			{
				ansA[j] = ansB[j] = '0';
				j++;
			}
			
			//ansA[j] = ansB[j] = '\0';
			//printf("%s %s\n", ansA, ansB);
			
			while (A[j] != '\0'&&A[j] == B[j] && A[j] != '?')
			{
				ansA[j] = ansB[j] = A[j];
				j++;
			}

			if (A[j] != '\0'&&A[j] > B[j])
			{
				ansA[j] = A[j];
				ansB[j] = B[j];
				aWin = 1;
			}
			else if (A[j] != '\0'&&A[j] < B[j])
			{
				ansA[j] = A[j];
				ansB[j] = B[j];
				aWin = 0;
			}


			if (A[j] != '\0'&&aWin == 1)
			{
				while (A[j] != '\0')
				{
					if (A[j] == '?')
					{
						ansA[j] = '0';
					}
					if (B[j] == '?')
					{
						ansB[j] = '9';
					}
					j++;
				}
			}
			else if (A[j] != '\0'&&aWin == 0)
			{
				while (A[j] != '\0')
				{
					if (A[j] == '?')
					{
						ansA[j] = '9';
					}
					if (B[j] == '?')
					{
						ansB[j] = '0';
					}
					j++;
				}
			}
			





			if (A[j] != '\0')
				j++;
		}
		ansA[j] = ansB[j] = '\0';
		printf("Case #%d: %s %s\n", i, ansA, ansB);


	}



	return 0;
}

