#include <iostream>
using namespace std;
void merge(int start,int end,int a[])
{
	int m=(start+end)/2;
	int i=start,j=m+1;
	int temp[5000];
	int k=0;
	while(i<=m&&j<=end)
	{
		if(a[i]<a[j])
		{
			temp[k++]=a[i];
			i++;
		}
		else
		{
			temp[k++]=a[j];
			j++;
		}
	}
	while(i<=m)	temp[k++]=a[i++];
	while(j<=end) temp[k++]=a[j++];
	for(i=0;i<end-start+1;i++)
		a[start+i]=temp[i];
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
	int n;
	cin>>n;
	int i,a[5000];
	for(i=0;i<n;i++)	cin>>a[i];
	mergesort(0,n-1,a);
	for(i=0;i<n;i++)	cout<<a[i]<<" ";
	return 0;
}