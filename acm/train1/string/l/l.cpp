#include <bits/stdc++.h>
using namespace std;
long long a,b,maxdep;
long long ans[1000]={0},v[1000];
long long getdiv(long long aa,long long bb)
{
	long long i,gcd,lcm;
	for(i=1;;i++)
	{
		gcd=__gcd(i,bb);
		lcm=gcd*i/gcd*bb/gcd;
		if(lcm/i<=aa*(lcm/bb))	return i;
	}
}
bool better(long long dep)
{
	/*
	long long i;
	for(i=dep;i>=0;i--)
	{
		if(ans[i]!=v[i])
		return ans[i]==0||v[i]<ans[i];
	}
	return false;*/
	return ans[dep]==0||v[dep]<ans[dep];
}
bool dfs(long long dep,long long from,long long aa,long long bb)
{
	long long i,j,k,l,gcd,lcm,a1,b1;
	bool find=false;
	if(dep==maxdep)
	{
		if(bb%aa)	return false;
		v[dep]=bb/aa;
		if(v[dep]==v[dep-1])	return false;
		if(better(dep))	memcpy(ans,v,sizeof(long long)*(dep+1));
		return true;
	}
	from=max(from,getdiv(aa,bb));
	for(i=from;;i++)
	{
		if(bb*(maxdep-dep+1)<aa*i)	break;
		gcd=__gcd(bb,i);
		lcm=gcd*(i/gcd)*(bb/gcd);
		a1=aa*(lcm/bb)-(lcm/i);;
		b1=lcm;
		gcd=__gcd(a1,b1);
		v[dep]=i;
		if(dfs(dep+1,i+1,a1/gcd,b1/gcd)) find=true;
	}
	return find;
}
int main()
{
	long long i;
	cin>>a>>b;
	if(b%a==0)
	{
		i=__gcd(a,b);
		cout<<b/i<<endl;
		return 0;
	}
	for(maxdep=1;;maxdep++)
	{
		if(dfs(0,getdiv(a,b),a,b))	break;
	}
	for(i=0;i<maxdep;i++)
		cout<<ans[i]<<" ";
	cout<<ans[i]<<endl;
	return 0;
}
