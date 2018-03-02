#include <stdio.h>
int main()
{
	int n,a[1000],b[1000];
	int i,j=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			printf("rated");
			j=1;
			break;
		}
	}
	if(j==0)
	{
		for(i=0;i<n-1;i++)
		{
			if(a[i+1]>a[i])
			{
				printf("unrated");
				j=1;
				break;
			}
		}
	}
	if(j==0)	printf("maybe");
	return 0;
}