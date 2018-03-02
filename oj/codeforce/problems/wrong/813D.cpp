//TLE

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define reset(a,b)	memset(a,0,sizeof(a))
LL ans=10000000000000;
LL n,k,p;
LL a[1010],b[2010];
void dfs(LL *use,LL deph,LL temp)
{
	if(deph==n)
	{
		if(temp<ans)	ans=temp;
		return ;
	}
	LL i,j;
	for(i=0;i<k;i++)
	{
		if(use[i]==0)
		{
			use[i]=1;
			dfs(use,deph+1,max(temp,abs(a[deph]-b[i])+abs(p-b[i])));
			use[i]=0;
		}
	}
}
int main()
{
	LL i,j,use[1010];
	cin>>n>>k>>p;
	for(i=0;i<n;i++)	cin>>a[i];
	for(i=0;i<k;i++)	cin>>b[i];
	sort(a,a+n);	sort(b,b+k);
	LL temp;
	reset(use,0);
	for(i=0;i<n;i++)
	{
		use[i]=1;
		dfs(use,1,abs(a[0]-b[i])+abs(p-b[i]));
		use[i]=0;
	}
	cout<<ans<<endl;
	return 0;
}