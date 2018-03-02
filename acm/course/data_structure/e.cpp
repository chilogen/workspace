#include <cstdio>
#include <map>
using namespace std;
long long int ans=0;
void merge(int start,int end,long int a[])
{
	int m=(start+end)/2;
	int i=start,j=m+1;
	long int temp[100000];
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
void mergesort(int start,int end,long int a[])
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
	int n,i;
	long int a[100000],b[100000],d[100000];
	map <long int,long int> c; 
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%ld",&a[i]);
	for(i=0;i<n;i++)
	{
		scanf("%ld",&b[i]);
		c[b[i]]=i;
	}
	for(i=0;i<n;i++)	d[i]=c[a[i]];
	//for(i=0;i<n;i++)	printf("%ld ",a[i]);
	mergesort(0,n-1,d);
	printf("%lld\n",ans);
	return 0;
}