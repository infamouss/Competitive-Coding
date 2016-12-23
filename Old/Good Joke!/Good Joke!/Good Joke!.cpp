// Good Joke!.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, N, ans, atmp, Xtmp, Ytmp;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		ans = N;
		N--;
		scanf("%d%d", &Xtmp, &Ytmp);
		while (N)
		{
			scanf("%d%d", &Xtmp, &Ytmp);
			atmp = ans;
			ans = atmp^N;
			N--;
		}
		printf("%d\n", ans);
	}
    return 0;
}

