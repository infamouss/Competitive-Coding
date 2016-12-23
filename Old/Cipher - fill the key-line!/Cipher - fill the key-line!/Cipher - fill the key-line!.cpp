#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

	int n, k, i, j, pre, cur, a[1000000];
	char input[2000000];

	scanf("%d", &n);
	scanf("%d", &k);
	scanf("%s", input);

	if (input[0] == '1')
		pre = 1;
	else
		pre = 0;

	printf("%d", pre);
	a[0] = pre;
	for (i = 1; i < n; i++) {
		if (input[i] == '1') {
			printf("%d", (pre ^ 1) & 1);
			a[i] = (pre ^ 1) & 1;
		}
		else {
			printf("%d", (pre ^ 0) & 1);
			a[i] = (pre ^ 0) & 1;
		}
		pre = pre ^ a[i];
		if ((i - k + 2) > 0)
		{








		}
	}
	printf("\n");
	return 0;
}
