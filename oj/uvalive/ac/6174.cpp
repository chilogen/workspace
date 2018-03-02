#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL a,b,c,p,k,n,ans,maxn,m[3];
	cin>>p;
	while(p--)
	{
		cin>>k>>n;
		ans=0;
		maxn=n>>1;
		for(a=maxn;a>0;a--)
		{
			for(b=(n-a)/2;b>0;b--)
			{
				if(b<a)	break;
				c=n-a-b;
				if(a+b<=c)	break;
				if(a!=b&&a!=c&&b!=c)	ans+=2;
				else ans++;
			}
		}
		cout<<k<<" "<<ans<<endl;
	}
	return 0;
}