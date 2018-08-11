#include <bits/stdc++.h>
#define reset(a,b)	memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
double ans=0;
LL con[100010],fir[100010],nex[100010],edge_num=0;
struct edge
{
	LL x,y;
}e[100010];
void dfs(LL x,double pro)
{
	if(con[x]==0)	return;
	ans+=pro;
	LL i,k;
	edge &g=e[fir[x]];	k=nex[fir[x]];
	dfs(g.y,pro/con[x]);
	while(k!=-1)
	{
		g=e[k];
		dfs(g.y,pro/con[x]);
		k=nex[k];
	}
}
inline void connect(LL u,LL v)
{
	edge_num++;
	e[edge_num].x=u;	e[edge_num].y=v;
	if(fir[u]!=-1)	nex[edge_num]=fir[u];
	fir[u]=edge_num;
	con[u]++;
}
int main()
{
	LL n,i,j,k,u,v;
	queue<LL>bfs;
	reset(con,0);	reset(fir,-1);	reset(nex,-1);
	cin>>n;
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&u,&v);
		connect(u,v);
	}
	edge &g=e[fir[1]];	k=nex[fir[1]];
	if(con[g.x]!=0)
	{
		ans+=1;
		dfs(g.y,1.0/con[g.x]);
	}
	while(k!=-1)
	{
		g=e[k];
		dfs(g.y,1.0/con[g.x]);
		k=nex[k];
	}
	printf("%.10lf\n",ans);
	return 0;
}