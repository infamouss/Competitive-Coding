// Valentine Special.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>


int main()
{
	int T;
	long N, i, AinB, BinA, AinC, CinA, BinC, CinB, numMoves;
	char arr[900001];
	scanf("%d", &T);
	while (T--)
	{
		AinB = AinC = BinA = BinC = CinA = CinB = numMoves = 0;
		scanf("%ld", &N);
		scanf("%s", arr);

		for (i = 0;i < N;i++)
		{
			switch (arr[i])
			{
			case 'a':
				break;
			case 'b':
				BinA++;
				break;
			case 'c':
				CinA++;
				break;
			}
		}
		for (;i < 2 * N;i++)
		{
			switch (arr[i])
			{
			case 'a':
				AinB++;
				break;
			case 'b':
				break;
			case 'c':
				CinB++;
				break;
			}
		}
		for (;i < 3 * N;i++)
		{
			switch (arr[i])
			{
			case 'a':
				AinC++;
				break;
			case 'b':
				BinC++;
				break;
			case 'c':
				break;
			}
		}




		
		

			if (AinB > BinA)
			{
				AinB = AinB - BinA;
				numMoves += BinA;
				BinA = 0;
			}
			else
			{
				BinA = BinA - AinB;
				numMoves += AinB;
				AinB = 0;
			}

			if (AinC > CinA)
			{
				AinC = AinC - CinA;
				numMoves += CinA;
				CinA = 0;
			}
			else
			{
				CinA = CinA - AinC;
				numMoves += AinC;
				AinC = 0;
			}

			if (BinC > CinB)
			{
				BinC + BinC - CinB;
				numMoves += CinB;
				CinB = 0;
			}
			else
			{
				CinB = CinB - BinC;
				numMoves += BinC;
				BinC = 0;
			}

		

		

			if (AinB != 0)
			{
				numMoves += 2 * AinB;
				AinB = 0;
			}
			else if(BinC!=0)
			{
				numMoves += 2 * BinC;
				AinC = 0;
			}
			else if(CinA!=0)
			{
				numMoves += 2 * CinA;
			}
			
			if (BinA != 0)
			{
				numMoves += 2 * BinA;
			}
			else if (AinC != 0)
			{
				numMoves += 2 * AinC;
			}
			else if (CinB != 0)
			{
				numMoves += 2 * CinB;
			}

		printf("%ld\n", numMoves);


	}


	return 0;
}

