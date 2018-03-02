#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL getham(LL x,LL y)
{
	LL i,j,k,l,ans=0;
	LL a[64],b[64];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	i=j=k=l=0;
	while(x)
	{
		if(x&1)	a[i]=1;
		else a[i]=0;
		i++;	x=x>>1;
	}
	while(y)
	{
		if(y&1)	b[j]=1;
		else b[j]=0;
		j++;	y=y>>1;
	}
	for(i=0;i<64;i++)
	{
		if(a[i]!=b[i])	ans++;
	}
	return ans;
}
int main()
{
	LL t,n,i,j,k,l,a[101],ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		ans=0;
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				k=getham(a[i],a[j]);
				ans=max(ans,k);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}