#include <bits/stdc++.h>
using namespace std;
long long quick(long long a,long long b,long long int mod)
{
	long long int ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		b=b>>1;
		a=a*a%mod;
	}
	return ans;
}
set<pair<long long int,long long int> >s;
int main()
{
	long long n,m,a,b,i,j;
	long long mod1,mod2;
	cin>>m>>n>>a>>b;
	a--;
	for(i=0;i<n;i++)
	{
		a++;
		mod1=quick(a,b-1,1e9+9);
		mod2=quick(a,b-1,1e9+7);
		for(j=0;j<m;j++)
		{
			mod1=(mod1*a)%(long long int)(1e9+9);
			mod2=(mod2*a)%(long long int)(1e9+7);
			s.insert(make_pair(mod1,mod2));
		}
	}
	cout<<s.size()<<endl;
	return 0;
}