#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
const LL mod=1e9+7;
#define MAXNUM 200000
LL quick(LL a,LL b,LL mod)
{
	LL ans=1;
	while(b)
	{
		if(b&1)
		{
			ans*=a;
			ans%=mod;
		}
		b=b>>1;
		a=(a*a)%mod;
	}
	return ans;
}
int main()
{
	string s;
	cin>>s;
	LL len=s.length(),ans=0,a1,a2,inv[MAXNUM+1],n[MAXNUM+1],i,k;
	LL l=0,r=0;
	n[0]=1;
	for(i=0;i<=MAXNUM;i++)
	{
		if(i<len&&s[i]=='1')	r++;
		if(i>0)
		{
			n[i]=i*n[i-1];
			n[i]=n[i]%mod;
			inv[i]=quick(n[i],mod-2,mod);
		}
	}
	for(i=0;i<len;i++)
	{
		if(s[i]=='1')	{r--;	continue;}
		else if(s[i]=='0')	l++;
		k=min(l,r);
		if(k==0)	a1=1;
		else
		{
			a1=(n[l+r]*inv[k])%mod;
			a1=(a1*inv[l+r-k])%mod;
			a1=(a1+mod)%mod;
		}
		k=min(l-1,r);
		if(k==0)	a2=1;
		else
		{
			a2=(n[l+r-1]*inv[k])%mod;
			a2=(a2*inv[l+r-1-k])%mod;
			a2=(a2+mod)%mod;
		}
		ans=(ans+(a1-a2+mod))%mod;
	}
	cout<<ans<<endl;
	return 0;
}