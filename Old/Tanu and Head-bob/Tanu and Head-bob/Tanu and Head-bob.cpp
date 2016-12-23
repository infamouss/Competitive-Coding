// Tanu and Head-bob.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, N, status;
	char str[1001];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		scanf("%s", str);
		status = 0;
		while (N-- && status == 0)
		{
			if (str[N] == 'I')
				status = 1;
			else if (str[N] == 'Y')
				status = -1;
		}
		printf("%s\n", (status == 0) ? "NOT SURE" : (status == 1) ? "INDIAN" : "NOT INDIAN");
	}
    return 0;
}

