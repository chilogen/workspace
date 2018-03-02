#include <bits/stdc++.h>
using namespace std;
#define MAXN 10
void method1(int n,string b="123456789")
{
	if(n>b.length())	return;
	int a[20],i,j,k,l;
	for(i=0;i<n;i++)	
	{
		a[i]=i;
		cout<<b[i]<<" ";
	}
	cout<<endl;
	while(1)
	{
		k=-1;
		for(i=n-1;i>0;i--)
		{
			if(a[i]<a[i-1])	continue;
			k=i-1;
			break;
		}
		if(k==-1)	break;
		l=k+1;	j=a[k+1];
		for(i=k+1;i<n;i++)
		{
			if(a[i]>a[k]&&a[i]<j)
			{
				l=i;	j=a[i];
			}
		}
		swap(a[l],a[k]);
		i=k+1;j=n-1;
		while(i<j)
		{
			swap(a[i],a[j]);
			i++;j--;
		}
		for(i=0;i<n;i++)
			cout<<b[a[i]]<<" ";
		cout<<endl;
	}
}
void method2(int n,int p,string b="123456789")
{
	if(n>b.length())	return;
	int i,j,k,l;
	if(p==n)
	{
		for(i=0;i<n;i++)	cout<<b[i]<<" ";
		cout<<endl;
		return ;
	}
	for(i=p;i<n;i++)
	{
		swap(b[i],b[p]);
		method2(n,p+1,b);
		swap(b[i],b[p]);
	}
}
int main()
{
	method1(3);
	method2(4,0);
	return 0;
}