// C. Technobabble.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
using namespace std;

void MergeA(int low, int mid, int high, string names[])
{
	int i = low, j = mid + 1, k = low;
	string Temp[5];

	while (i <= mid && j <= high)
	{
		if (names[i] < names[j])
		{
			Temp[k].assign(names[i]);
			i++;
		}
		else
		{
			Temp[k].assign(names[j]);
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		for (int h = j;h <= high; h++)
		{
			Temp[k].assign(names[h]);
			k++;
		}
	}
	else
		for (int h = i; h <= mid; h++)
		{
			Temp[k].assign(names[h]);
			k++;
		}
	for (int i = low; i <= high; i++)
	{
		names[i].assign(Temp[i]);
	}
}
void MergeSortA(int low, int high, string names[])
{
	int mid = 0;
	if (low < high)
	{
		mid = ((low + high) / 2);
		MergeSortA(low, mid, names);
		MergeSortA(mid + 1, high, names);
		MergeA(low, mid, high, names);
	}
}


int binarySearch(string names[], int size, string value)
{
	int first = 0,
		last = size - 1,
		middle,
		position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (names[middle] == value)
		{
			found = true;
			position = middle;
		}
		else if (names[middle] > value)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}

int main()
{
	int T, N, i, j, Ans, index;
	string string1[1001], string2[1001], s1dup[1001], s2dup[1001];
	cin >> T;

	for (i = 1;i <= T;i++)
	{
		cin >> N;
		Ans = 0;
		for (j = 0;j < N;j++)
		{
			cin >> string1[j] >> string2[j];
			s1dup[j].assign(string1[j]);
			s2dup[j].assign(string2[j]);
		}

		MergeSortA(0, N, string1);
		MergeSortA(0, N, string2);


		for (j = 0;j < N;j++)
		{
			index = binarySearch(string1, N, s1dup[j]);

			if (string1[index] == string1[index + 1]|| string1[index] == string1[index - 1])
			{


				index = binarySearch(string2, N, s2dup[j]);
				if (string2[index] == string2[index + 1] || string2[index] == string2[index - 1])
				{
					Ans++;
				}


			}



		}



		cout << Ans << endl;



	}





	return 0;
}

