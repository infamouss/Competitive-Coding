// Prateek and Alarm Clock.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, H, M;
	float Ah, Am, ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &H, &M);
		H = (H >= 12) ? H - 12 : H;
		Am = (float)M * 360 / 60;
		Ah = (float)H * 360 / 12 + (float)M * 30 / 60;
		ans = Ah - Am;
		ans = (ans >= 0) ? ans : ans*-1;
		ans = (ans > 180) ? 360 - ans : ans;
		printf("%.2f\n", ans);
	}
	return 0;
}

