// Resolutions.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>
#include <string.h>


void tostring(int value, char out[])
{
	int i = 0;
	while (value != 0)
	{
		out[i] = value % 10 + '0';
		value = value / 10;
		i++;
	}
	out[i] = '\0';
	strrev(out);
}

void extractNum(char inp[], float factor, char out[])
{
	int i, j, k, value = 0, mul = 1;
	char num[10];
	i = 0;
	while (inp[i]<'0' || inp[i]>'9')
	{
		i++;
	}
	printf("%d\n", i);
	while (inp[i] - '0' >= 0 && inp[i] - '0' <= 9)
	{
		value += (inp[i] - '0')*mul;
		mul *= 10;
		i++;
	}
	value = round(factor*value);
	tostring(value, num);
	strrev(inp);
	i = 0;
	while (inp[i]<'0' || inp[i]>'9')
	{
		out[i] = inp[i];
		i++;
	}
	k = i;
	j = 0;
	while (num[j] != '\0')
	{
		out[i] = num[j];
		i++;
		j++;
	}
	while (inp[k] >= '0'&&inp[k] <= '9')
	{
		k++;
	}
	while (inp[k] != '\0')
	{
		out[i] = inp[k];
		k++;
		i++;
	}
	out[i] = '\0';
	printf("%s", out);
}




int main()
{
	int i, j, k, count = 1, value;
	float factor = 2;
	FILE *ip, *op;
	char tmp1[1000], tmp2[1000], tmp3[1000], tmp4[1000], inp[1000], out[1000];
	printf("Enter factor:\n");
	scanf("%f", &factor);
	ip = fopen("dimens.xml", "r");
	op = fopen("output.xml", "w");
	while (!feof(ip) && count < 22)
	{
		if (count >= 3 && count <= 20)
		{
			fgets(inp, 100, ip);
			strrev(inp);
			//printf("%c", inp[0]);
			printf("%s\n", inp);
			extractNum(inp, factor, out);
			fprintf(op, "%s", out);
		}
		else
		{
			fgets(inp, 100, ip);
			fprintf(op, "%s", inp);
		}
		count++;
	}
	fclose(ip);
	fclose(op);
	printf("Check file output.xml\n");
	return 0;
}

