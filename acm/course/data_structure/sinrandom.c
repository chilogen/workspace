#include <stdio.h>
#include <stdlib.h>

void sinrandom(int n,int a[])
{
	int b[100000];
	int i;
	for(i=0;i<n;i++)
	{
		b[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		int x=rand()%(n-i);
		a[i]=b[x];
		b[x]=b[n-i-1];
	}
}
int main()
{
	freopen("abc","w",stdout);
	int a[100000],b[100000];
	int n,ran,i;
	scanf("%d%d",&n,&ran);
	srand(ran);
	printf("%d\n",n);
	sinrandom(n,a);
	for(i=0;i<n;i++)	printf("%d ",a[i]);
	printf("\n");
	sinrandom(n,b);
	for(i=0;i<n;i++)	printf("%d ",b[i]);
	fclose(stdout);
	return 0;
}