// 1A - Bear and Vowels.cpp : Defines the entry point for the console application.
// url : https://www.hackerearth.com/april-circuits/algorithm/circ-bear-and-vowels-2/

#include <stdio.h>


int main()
{
	int T, i, j, cCount, vCount, cCons, ans;
	char ip[51];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", ip);
		cCount = vCount = cCons = i = 0;
		ans = 0;
		while (ip[i] != '\0'&&ans == 0)
		{
			if (ip[i] == 'a' || ip[i] == 'e' || ip[i] == 'i' || ip[i] == 'o' || ip[i] == 'u' || ip[i] == 'y')
			{
				vCount++;
				cCons = 0;
			}
			else
			{
				cCount++;
				cCons++;
				if (cCons == 3)
				{
					ans = 1;
				}
			}
			i++;
		}
		ans = (cCount > vCount) ? 1 : 0;
		printf("%s\n", (ans == 0) ? "easy" : "hard");
	}
	return 0;
}

