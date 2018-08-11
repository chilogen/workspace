#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[300];
bool cmp(LL c,LL d)
{
	LL i,j,k,a=0,b=0;
	i=c;	j=d;
	while(i%2==0)
	{
		i=i/2;
		a++;
	}
	while(j%2==0)
	{
		j=j/2;
		b++;
	}
	if(i!=1&&j!=1)
	{
		if(a!=b)	return a<b;
		else return c<d;
	}
	if(i==1&&j==1)
	{
		return c>d;
	}
	if(i==1&&j!=1)
	{
		return false;
	}
	if(i!=1&&j==1)
	{
		return true;
	}
}
int main()
{
	LL n,i,j,k;
	cin>>n;
	while(n--)
	{
		k=0;
		while(1)
		{
			cin>>i;
			if(i==0)	break;
			a[k++]=i;
		}
		sort(a,a+k,cmp);
		for(i=0;i<=k-2;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<a[i]<<endl;
	}
	return 0;
}