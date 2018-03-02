#include <bits/stdc++.h>
using namespace std;
#define reset(a,b)	memset(a,b,sizeof(a))
typedef long long LL;
struct edge
{
	LL u,v,w;
};
edge e[200010];
LL fir[10010],nex[200010],dst[10010],way[10010];
LL v,E,s,t;
const LL INF=(LL)(1e16);
queue<LL>q;
void dfs(LL x,LL ans)
{
	LL i,j,k=-1;
	edge tmp;
	ans=ans*way[x];
	if(x==t)	{cout<<ans<<endl;	exit(0);}
	if(fir[x]!=-1)
	{
		k=nex[fir[x]];
		tmp=e[fir[x]];
		if(dst[tmp.v]==dst[tmp.u]+tmp.w)
		{
			dfs(tmp.v,ans);
		}
	}
	while(k!=-1)
	{
		tmp=e[k];
		if(dst[tmp.v]==dst[tmp.u]+tmp.w)
		{
			dfs(tmp.v,ans);
		}
		k=nex[k];
	}
}
int main()
{
	LL i,j,k,x,y,z;
	edge tmp;
	reset(fir,-1);
	reset(nex,-1);
	reset(way,0);
	cin>>v>>E;
	for(i=0;i<E;i++)
	{
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
		if(fir[e[i].u]!=-1)
			nex[i]=fir[e[i].u];
		fir[e[i].u]=i;
	}
	for(i=0;i<=v;i++)	dst[i]=INF;
	cin>>s>>t;
	q.push(s);
	dst[s]=0;	way[s]=1;
	while(!q.empty())
	{
		i=q.front();	q.pop();
		k=-1;
		if(fir[i]!=-1)
		{
			k=nex[fir[i]];
			tmp=e[fir[i]];
			if(dst[tmp.v]==dst[tmp.u]+tmp.w)
			{
				way[tmp.v]+=way[tmp.u];
				
			}
			else if(dst[tmp.v]>dst[tmp.u]+tmp.w)
			{
				dst[tmp.v]=dst[tmp.u]+tmp.w;
				q.push(tmp.v);
				way[tmp.v]=way[tmp.u];
			}
		}
		while(k!=-1)
		{
			tmp=e[k];
			if(dst[tmp.v]==dst[tmp.u]+tmp.w)
				way[tmp.v]+=way[tmp.u];
			else if(dst[tmp.v]>dst[tmp.u]+tmp.w)
			{
				dst[tmp.v]=dst[tmp.u]+tmp.w;
				q.push(tmp.v);
				way[tmp.v]=way[tmp.u];
			}
			k=nex[k];
		}
	}
	dfs(s,1);
	cout<<0<<endl;
	return 0;
}