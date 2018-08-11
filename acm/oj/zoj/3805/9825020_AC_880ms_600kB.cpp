#include <bits/stdc++.h>
#define reset(a,b)	memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
LL deg[10001],wid[10001],conect[10001][2];
LL getwid(LL x)
{
	LL l,r;
	if(x==-1)	return 0;
	if(deg[x]==0)	return 1;
	l=getwid(conect[x][0]);	r=getwid(conect[x][1]);
	return max(min(l+1,r+1),max(l,r));	
}
int main()
{
	LL n,i,j,k,l,ans;
	while(scanf("%lld",&n)!=EOF)
	{
		reset(deg,0);	reset(wid,0);	reset(conect,-1);
		for(i=2;i<=n;i++)
		{
			scanf("%lld",&j);
			if(conect[j][0]!=-1)	conect[j][1]=i;
			else conect[j][0]=i;
			deg[j]++;
		}
		i=getwid(conect[1][0]);	j=getwid(conect[1][1]);
		k=min(i+1,j+1);
		printf("%lld\n",max(k,max(i,j)));
	}
	return 0;
}