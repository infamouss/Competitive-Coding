// Encryption.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	char str[82];
	int i, j, L, M, len;
	scanf("%s", str);
	len = strlen(str);
	L = floor(sqrt(len));
	M = ceil(sqrt(len));
	if (L*M < len)
	{
		L = M;
	}
	for (i = 0;i < M;i++)
	{
		for (j = i;j<len;j+=M)
		{
			printf("%c", str[j]);
		}
		printf(" ");
	}

	return 0;
}

