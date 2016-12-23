#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
int lonelyinteger(int a_size, int* a) {
	int i = 0;
	int num = 0;
	for (i = 0; i < a_size; i++){
		int arr[100] = { 0 };
		if (i == a_size - 1)
			for (int k = 0; k < a_size; k++)
			{
				++arr[a[k]];
				if (k == a_size - 1)
				{
					int flag = 0;
					for (int j = 0; flag == 0; j++)
					{
						if (arr[a[j]] == 1)
						{
							flag = 1;
							num = a[j];
						}
					}
				}
			}
	}

	return num;

}
int main() {
	int res;

	int _a_size, _a_i;
	scanf("%d", &_a_size);
	int _a[_a_size];
	for (_a_i = 0; _a_i < _a_size; _a_i++) {
		int _a_item;
		scanf("%d", &_a_item);

		_a[_a_i] = _a_item;
	}

	res = lonelyinteger(_a_size, _a);
	printf("%d", res);

	return 0;
}

