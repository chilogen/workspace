#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ita(long int x,char *a)
{
	int i=31,j,len;
	for(j=0;j<32;j++)
		a[j]='0';
	while(x>1)
	{
		j=x%2;
		a[i]='0'+j;
		x=x/2;
		i--;
	}
	if(x!=0) a[i]='0'+x;
	a[32]='\0';
	return ;
}

void ati(long int *x,char *a)
{
	int i=31;
	long int j=1;
	*x=0;
	while(i>=0)
	{
		*x=*x+(a[i]-'0')*j;
		j=j*2;
		i--;
	}
}

int main()
{
	long int a,b;
	int len;
	char c[33];
	scanf("%ld",&a);
	ita(a,c);
	len=strlen(c);
	printf("%s %d\n",c,len);
	ati(&b,c);
	printf("%ld\n",b);
	return 0;
}