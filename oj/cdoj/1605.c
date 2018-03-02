#include <stdio.h>
int main()
{
	long a[100]={0};
	int n,i;
	long int j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a[i/10000]+=i;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%ld",&j);
		a[j/10000]-=j;
	}
	for(i=0;i<100;i++)
	{
		if(a[i]!=0)	{printf("%ld",a[i]);	break;}
	}
	return 0;
}