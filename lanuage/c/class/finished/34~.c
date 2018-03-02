#include<stdio.h>
#include<string.h>
void my_strcat(char * d,const char * s)
{
	if(d==0|s==0){printf("error"); return;}
	int lend=strlen(d),lens=strlen(s);
	if(lend+lens>(int)sizeof(d)){printf("error"); return;}
	int lop,loop;
	for(lop=0;lop<lend;lop++)
	{
		if(d[lop]=='\0') break;
	}
	for(loop=0;loop<lens;loop++)
	{
		if(s[loop]!='\0') d[lop+loop]=s[loop];
		else break;
	}
	d[lop+loop]='\0';
}
int main()
{
	char d[10]={},s[5]={};
	my_strcat(d,s);
	printf("%s",d);
	return 0;
}
