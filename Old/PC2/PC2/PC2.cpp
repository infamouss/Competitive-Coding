// PC2.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	//char ip[1000]="g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp. bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. lmu ynnjw ml rfc spj";
	char ip[1000] = "map";
	int i = 0;
	while (ip[i] != '\0')
	{
		if(ip[i]>='a'&&ip[i]<='z')
			ip[i] = (ip[i] - 'a' + 2) % 26 + 'a';




		i++;
	}

	printf("%s", ip);


	return 0;
}

