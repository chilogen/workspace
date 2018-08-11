#include <cstdio>
int ans=0;
void merge(int start,int end,int a[])
{
	int m=(start+end)/2;
	int i=start,j=m+1;
	int temp[100000];
	int k=start;
	while(i<=m&&j<=end)
	{
		if(a[i]>a[j])
		{
			temp[k++]=a[j++];
			ans+=m-i+1;
		}
		else
		{
			temp[k++]=a[i++];
		}
	}
	while(i<=m)	temp[k++]=a[i++];
	while(j<=end) temp[k++]=a[j++];
	for(i=start;i<=end;i++)
		a[i]=temp[i];
}
void mergesort(int start,int end,int a[])
{
	int m=(start+end)/2;
	if(end>start)
	{
		mergesort(start,m,a);
		mergesort(m+1,end,a);
		merge(start,end,a);
	}
}
int main()
{
	int n,k,i,t=1;
	freopen("abc","r",stdin);
	int a[100000];
	scanf("%d",&n);
	while(n--)
	{
		ans=0;
		scanf("%d",&k);
		for(i=0;i<k;i++)	scanf("%d",&a[i]);
		mergesort(0,k-1,a);
		printf("Scenario #%d:\n%d\n\n",t++,ans);
	}
	fclose(stdin);
	return 0;
}