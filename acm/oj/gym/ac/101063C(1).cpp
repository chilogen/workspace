#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL f[1025]={0};
double num(LL x)
{
	double ans=0;
	while(x)
	{
		if(x&1)	ans++;
		x=x>>1;
	}
	return ans;
}
inline LL C(LL n)
{
	return n*(n-1)/2;
}
int main()
{
	LL n,m,i,j,l,q,temp;
	double k;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>q;
		temp=0;
		for(l=0;l<q;l++)
		{
			cin>>j;
			temp=temp|1<<(j-1);
		}
		f[temp]++;
	}
	cin>>k;
	LL ans=0;
	double a1,a2;
	for(i=1;i<=1024;i++)
	{
		if(!f[i])	continue;
		for(j=i;j<=1024;j++)
		{
			if(!f[j])	continue;
			if(i!=j)
			{
				a1=num(i&j);
				a2=num(i|j);
				if(a1/a2>=k)	ans+=f[i]*f[j];
			}
			if(i==j)
			{
				ans=ans+C(f[i]);
			}
		}
	}
	cout<<ans;
}