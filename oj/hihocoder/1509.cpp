#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL po(LL a,LL x)
{
	LL ans=1;
	while(x>0)
	{
		if(x&1)
		{
			ans=ans*a;
		}
		x=x>>1;
		a=a*a;
	}
	return ans;
}
int main()
{
	LL a[60],bit[70];
	LL n,i,j,k,p,q,one=1;
	cin>>n;
	for(i=0;i<n;i++)	cin>>a[i];
	memset(bit,-1,sizeof(bit));
	for(i=0;i<n-1;i++)
	{
		k=60;
		while(k>=0)
		{
			p=(one<<k)&a[i];
			q=(one<<k)&a[i+1];
			if(p==0&&q>0)
			{
				bit[k]=0;
				break;
			}
			else if(p>0&&q==0)
			{
				bit[k]=1;
				break;
			}
			k--;
		}
	}
	for(i=0,j=0;i<60;i++)
	{
		if(bit[i]==-1)	j++;
	}
	i=po(2,j);
	cout<<i<<endl;
	return 0;
}