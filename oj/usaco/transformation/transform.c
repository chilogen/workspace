/*
ID: quantu_1
LANG : C
TASK : transform
*/
#include<stdio.h>
#include<malloc.h>
int N;
char **fmartrix,**amartrix;
void print()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		printf("%c ",fmartrix[i][j]);
		printf("\n");
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		printf("%c ",amartrix[i][j]);
		printf("\n");
	}
}
int main()
{
	int compare(char**);
	int reflec(char**);
	int rotate(char**);
	int bool,m1=0,m2=0;
	FILE *in=fopen("transform.in","r"),*out=fopen("transform.out","w");
	fscanf(in,"%d",&N);
	fmartrix=(char**)malloc(sizeof(char)*N);
	amartrix=(char**)malloc(sizeof(char)*N);
	int i,j;
	for(i=0;i<N;i++)
	{
		fmartrix[i]=(char*)malloc(sizeof(char)*N);
		amartrix[i]=(char*)malloc(sizeof(char)*N);
	}
	for(i=0;i<N;i++)
	for(j=0;j<N;j++)
	{	
		fscanf(in,"%c",&fmartrix[i][j]);
		if(fmartrix[i][j]=='\n') j--;
	}
	for(i=0;i<N;i++)
	for(j=0;j<N;j++)
        {
		fscanf(in,"%c",&amartrix[i][j]);
		if(amartrix[i][j]=='\n') j--;
	}
	fclose(in);
	bool=compare(fmartrix);
	if(bool==0){fprintf(out,"6\n"); fclose(out); return 0;}
	if(reflec(fmartrix)==0) {fprintf(out,"4\n"); fclose(out); return 0;}
	for(m1=0;m1<4;m1++)
	{
		if(rotate(fmartrix)==0) {fprintf(out,"%d\n",m1+1); fclose(out); return 0;}
		if(reflec(fmartrix)==0) {fprintf(out,"5\n"); fclose(out); return 0;}
	}
	fprintf(out,"7\n");
	fclose(out);
	return 0;
}
int compare(char **c)
{
	int i,j;
	for(i=0;i<N;i++)
	for(j=0;j<N;j++)
		if(c[i][j]!=amartrix[i][j]) return 1;
	return 0;
}
int reflec(char **c)
{
	int i,j,k;
	for(j=0;j<N;j++)
	for(i=N-1,k=0;i>-1;i--,k++)
		if(c[i][j]!=amartrix[k][j]) return 1;
	return 0;
}
int rotate(char **c)
{
	char **s;
	int i,j,k;
	s=(char**)malloc(sizeof(char)*N);
	for(i=0;i<N;i++)
	{
		s[i]=(char*)malloc(sizeof(char)*N);
		for(j=0;j<N;j++)
		s[i][j]=c[i][j];
	}
	for(i=0;i<N;i++)
	for(j=0,k=N-1;j<N;j++,k--)
	{
		c[i][j]=s[k][i];
	}
	return compare(c);
}
