// Word count.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class word
{
public:
	int count;
	char ch[25];
	char c[25];
};

int main()
{
	word w;
	char fileName[20];
	int numFiles;
	ifstream fin;
	cout << "Enter numbaer of files\n";
	cin >> numFiles;
	cout << "Enter the word to be count\n";
	scanf("%s",w.c);
	w.count = 0;
	for (int i = 0;i < numFiles;i++)
	{
		cout << "Enter file name\n";
		cin >> fileName;
		fin.open(fileName);
		while (!fin.eof())
		{
			fin >> w.ch;
			if (strcmpi(w.ch, w.c) == 0)
			{
				w.count = w.count + 1;
			}
		}
		fin.close();
	}
	
	cout << "Occurences=" << w.count << endl;
	
	return 0;
}
