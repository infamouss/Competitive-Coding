// Dijkstra.cpp : Defines the entry point for the console application.
//

#include <stdio.h>



int dijkstra(char str[], int size, long long multiplier)
{
	int retval = 0, i = 1, minus = 0;
	char last;
	while (str[i] != '\0')
	{
		switch (str[i-1])
		{
		case '1':
			switch (str[i])
			{
			case 'i':
				str[i] = 'i';
				break;
			case 'j':
				str[i] = 'j';
				break;
			case 'k':
				str[i] = 'k';
				break;
			}
			break;
		case 'i':
			switch (str[i])
			{
			case 'i':
				minus++;
				str[i] = '1';
				break;
			case 'j':
				str[i] = 'k';
				break;
			case 'k':
				minus++;
				str[i] = 'j';
				break;
			}
			break;
		case 'j':
			switch (str[i])
			{
			case 'i':
				minus++;
				str[i] = 'k';
				break;
			case 'j':
				minus++;
				str[i] = '1';
				break;
			case 'k':
				str[i] = 'i';
				break;
			}
			break;
		case 'k':
			switch (str[i])
			{
			case 'i':
				str[i] = 'j';
				break;
			case 'j':
				minus++;
				str[i] = 'i';
				break;
			case 'k':
				minus++;
				str[i] = '1';
				break;
			}
			break;
		}

		i++;
	}
	last = str[i - 1];

	minus = minus % 2;
	


	if (last == '1')
	{
		if (multiplier = multiplier % 2 == 0)
		{
			minus = 0;
		}
		else
		{
			minus = minus;
		}
	}
	else
	{
		switch (multiplier = multiplier % 4)
		{
		case 0:						//+1
			last = '1';
			minus = 0;
			break;
		case 1:						//same
			last = last;
			minus = minus;
			break;
		case 2:						//sign change


			last = '1';
			minus = 1;


			break;
		case 3:						//only sign change
			last = last;
			minus = (minus + 1) % 2;
			break;
		}
	}
	




	if (last == '1' && minus == 1)
	{
		retval = 1;
	}
	else
	{
		retval = 0;
	}

	return retval;


}





int main()
{
	int T, L, i, j, k, ans;
	long long X;
	char str[10005];
	FILE *inputFile, *outputFile;
	inputFile = fopen("C-small-attempt0.in", "r");
	outputFile = fopen("OUTPUT.txt", "w");
	fscanf(inputFile, "%d", &T);
	for (i = 1; i <= T; i++)
	{
		fscanf(inputFile, "%d%lld", &L, &X);
		fscanf(inputFile, "%s", str);
		if (L*X < 3)
		{
			fprintf(outputFile, "Case #%d: NO\n", i);
		}
		else
		{
			ans = dijkstra(str, L, X);
			if (ans == 1)
			{
				fprintf(outputFile, "Case #%d: YES\n", i);
			}
			else
			{
				fprintf(outputFile, "Case #%d: NO\n", i);
			}
		}
	}
	return 0;
}

