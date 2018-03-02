#include<stdio.h>
#include<string.h>

int main()
{
	char a[50][500];
	int i=0;
	FILE *p=fopen("oj","r");
	while(fscanf(p,"%s",a[i])!=EOF)
	{
		i++;
	};
	i--;
	while(i>-1)
	{
		printf("%s ",a[i]);
		i--;
	}
	return 0;
}
