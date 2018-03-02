#include<stdio.h>
int main()
{
	int a[500],n,k=2;
	a[0]=1; a[1]=1;
	scanf("%d",&n);
	while(n>k)
	{
		a[k]=a[k-1]+a[k-2];
		k++;
	}
	printf("%d",a[n-1]);
	return 0;
}
