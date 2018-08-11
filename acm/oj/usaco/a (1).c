#include<stdio.h>
#include<malloc.h>
int main()
{
	FILE *in=fopen("in","r");
/*	char **a;*/
	char a[100][100];
	int i,j;
	/*a=(char **)malloc(sizeof(char)*100);*/
	for(i=0;i<100;i++)
	{
		/*a[i]=(char*)malloc(sizeof(char)*100);*/
		for(j=0;j<100;j++)
		fscanf(in,"%c",&a[i][j]);
	}
	fclose(in);
	return 0;
}
