#include<stdio.h>
#include<string.h>
int main()
{
	char s[30];
	scanf("%s",s);
	int len=strlen(s),lop;
	for(lop=0;lop<=len/2;lop++)
	{
		if(s[lop]!=s[len-lop-1]) break;
	}
	if(lop!=len/2+1) printf("false");
	else printf("true");
	return 0;
}
