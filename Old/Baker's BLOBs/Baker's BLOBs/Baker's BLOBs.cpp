// Baker's BLOBs.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include<string.h>
#include<stdlib.h>


int OR(char str[], long int end);
int AND(char str[], long int end);
int XOR(char str[], long int end);
void reverse(char str[], long int end);
void flippingBits(char str[], long int mid, long int end);

int main()
{
	char strOR[1000000];
	char *strAND, *strXOR;
	int t, ansOR = 0, ansAND = 0, ansXOR = 0;
	long int end;
	scanf("%d", &t);
	while (t)
	{
		scanf("%s", strOR);
		end = strlen(strOR);
		strAND = (char*)malloc(sizeof(char)*(end + 1));
		strXOR = (char*)malloc(sizeof(char)*(end + 1));
		strcpy(strAND, strOR);
		strcpy(strXOR, strOR);
		//printf("%s\n%s\n%s\n", strOR, strAND, strXOR);
		ansOR = OR(strOR, end);
		ansAND = AND(strAND, end);
		ansXOR = XOR(strXOR, end);
		

		if (ansOR == 0)
			printf("blueberry ");
		else
			printf("chocolate ");
		if (ansAND == 0)
			printf("medium ");
		else
			printf("large ");
		if (ansXOR == 0)
			printf("stale\n");
		else
			printf("fresh\n");

		free(strAND);
		free(strXOR);
		t--;
	}
	return 0;
}


int OR(char str[], long int end)
{
	long int mid, start = 0, i, j;
	int ans;
	
	if (end==1)
	{
		ans = (int)str[0] - (int)'0';
	}
	else
	{
		mid = end / 2;
		reverse(str, mid);
		flippingBits(str, mid, end);
		j = mid;
		for (i = 0; i < mid; i++, j++)
		{
			if (str[i] == '0' && str[j] == '0')
			{
				str[i] = '0';
			}
			else
				str[i] = '1';
		}
		
		ans = OR(str, mid);
	}
	return ans;
	

}


int AND(char str[], int long end)
{
	long int mid, start = 0, i, j;
	int ans;
	
	if (end==1)
	{
		ans = (int)str[0] - (int)'0';
	}
	else
	{
		mid = end / 2;
		reverse(str, mid);
		flippingBits(str, mid, end);
		j = mid;
		for (i = 0; i < mid; i++, j++)
		{
			if (str[i] == '1' && str[j] == '1')
			{
				str[i] = '1';
			}
			else
				str[i] = '0';
		}
		
		ans = AND(str, mid);
	}
	return ans;

}


int XOR(char str[], long int end)
{
	long int mid, start = 0, i, j;
	int ans;
	
	if (end==1)
	{
		ans = (int)str[0] - (int)'0';
	}
	else
	{
		mid = end / 2;
		reverse(str, mid);
		flippingBits(str, mid, end);
		j = mid;
		for (i = 0; i < mid; i++, j++)
		{
			if ((str[i] == '0' && str[j] == '0') || (str[i] == '1' && str[j] == '1'))
			{
				str[i] = '0';
			}
			else
				str[i] = '1';
		}
		
		ans = XOR(str, mid);
	}
	return ans;


}



void reverse(char a[], long int end)
{
	long int i, mid;
	char tmp;
	mid = end / 2;
	for (i = 0; i < mid; i++)
	{
		tmp = a[i];
		a[i] = a[end - 1 - i];
		a[end - 1 - i] = tmp;
	}
}





void flippingBits(char a[], long int start, long int end)
{
	long int i;
	char tmp;
	if (start > 1)
	{
		for (i = start; i < end; i += 2)
		{
			tmp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = tmp;
		}
	}		
}