// SimilarWords.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int  inputWords;
char **inputArray;
int  *firstWordIndex;
int  *similarWordIndex;

/*extern*/ int SimilarWords();




int similarString(char s1[], char s2[]);
void copyString(char s1[], int start1, char p1[], char s2[], int start2, char p2[]);

int main(int argc, char* argv[])
{

	int i, count;
	cin >> inputWords;

	inputArray = new char*[inputWords];
	for (i = 0; i < inputWords; i++)
		inputArray[i] = new char[50];

	firstWordIndex = new int[inputWords*inputWords];
	similarWordIndex = new int[inputWords*inputWords];
	for (i = 0; i < inputWords; i++)
	{
		cin >> inputArray[i];
	}


	count = SimilarWords();

	for (i = 0; i < count; i++)
	{
		cout << firstWordIndex[i] << " " << similarWordIndex[i] << endl;
	}



	return 0;
}












int SimilarWords()
{
	int  index;                   /* for the first word of pair */
	int  numPairs = 0;                   /* Similar Words pair Number */


	int i, j, k, flag = 0, flag1 = 0;
	for (i = 0; i < inputWords - 1; i++)
	{
		for (j = i + 1; j < inputWords; j++)
		{
			flag = 0;
			k = 0;

			flag = similarString(inputArray[i], inputArray[j]);

			if (flag == 1)
			{
				flag1 = 0;
				for (k = 0; k < numPairs && flag1 == 0; k++)
				{
					if ((strcmp(inputArray[firstWordIndex[k]], inputArray[i]) == 0 && strcmp(inputArray[similarWordIndex[k]], inputArray[j]) == 0) || (strcmp(inputArray[firstWordIndex[k]], inputArray[j]) == 0 && strcmp(inputArray[similarWordIndex[k]], inputArray[i]) == 0))
					{
						flag1 = 1;
					}
				}
				if (flag1 == 0)
				{
					/*ans[numPairs][0] = i;
					ans[numPairs][1] = j;*/
					firstWordIndex[numPairs] = i;
					similarWordIndex[numPairs] = j;
					numPairs++;
				}

			}
		}
	}
	return numPairs;
}



int similarString(char s1[], char s2[])
{
	int i = 0, j, retval;
	int flag = 0, flag1 = 0, flag2 = 0;
	char p1[50], p2[50];
	int tmp;
	while (s1[i] == s2[i] && flag1 == 0 && flag2 == 0)
	{
		if (s1[i] == '\0')
		{
			flag1 = 1;
		}
		if (s2[i] == '\0')
		{
			flag2 = 1;
		}
		i++;
	}
	tmp = 2 * flag2 + flag1;
	switch (tmp)
	{
	case 0:
		copyString(s1, i, p1, s2, i + 1, p2);
		if (strcmp(p1, p2) == 0)
		{
			retval = 1;
		}
		else
		{
			copyString(s1, i + 1, p1, s2, i, p2);
			if (strcmp(p1, p2) == 0)
			{
				retval = 1;
			}
			else
			{
				copyString(s1, i + 1, p1, s2, i + 1, p2);
				if (strcmp(p1, p2) == 0)
				{
					retval = 1;
				}
				else
				{
					retval = 0;
				}
			}
		}


		break;
	case 1:
		if (s2[i + 1] == '\0')
			retval = 1;
		break;
	case 2:
		if (s1[i + 1] == '\0')
			retval = 1;
		break;
	case 3:
		retval = 0;
		break;
	}


	return retval;
}



void copyString(char s1[], int start1, char p1[], char s2[], int start2, char p2[])
{
	int i = start1;
	int j = 0;
	while (s1[i] != '\0')
	{
		p1[j] = s1[i];
		i++;
		j++;
	}
	p1[j] = '\0';
	i = start2;
	j = 0;
	while (s2[i] != '\0')
	{
		p2[j] = s2[i];
		i++;
		j++;
	}
	p2[j] = '\0';
}
