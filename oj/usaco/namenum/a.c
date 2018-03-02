/*
ID: quantu_1
LANG: C
TASK: namenum
*/
#include<stdio.h>
#include<string.h>
int main()
{
	FILE *dict,*in,*out;
	dict=fopen("dict.txt","r");
	in=fopen("namenum.in","r");
	out=fopen("namenum.out","w");
	
	char di[5000][10],num[10];
	char map[8][3]={{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};
	int lop,loop;
	for(lop=0;lop=5000;lop++)
	{
		fscanf(dict,"%s",di[lop]);
	}
	fclose(dict);
	
	fscanf(dict,"%s",num);
	fclose(in);

	for(lop=0;lop<strlen(num);lop++)
	{
		
	}
	fclose(out);
	return 0;
}
