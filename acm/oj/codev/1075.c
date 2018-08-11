#include<stdio.h>
int main()
{
	int a[1000],i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	for(j=0;j<n-i-1;j++)
	{
		if(a[j]>a[j+1])
		{
			a[j]=a[j+1]^a[j];
			a[j+1]=a[j]^a[j+1];
			a[j]=a[j+1]^a[j];
		}
	}
	for(i=1,j=1;i<n;i++)
	{
		if(a[i]!=a[i-1]) {a[j]=a[i]; j++;}
	}
	printf("%d\n",j);
	for(i=0;i<j;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
