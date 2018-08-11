#include <bits/stdc++.h>
#define reset(a,b)	memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
double pro[100010];
LL con[100010],fir[100010],nex[100010],edge_num=0;
struct edge
{
	LL x,y;
}e[100010];
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
	double ans=0;
	LL n,i,j,k,u,v;
	queue<LL>bfs;
	reset(pro,0);	reset(con,0);	reset(fir,-1);	reset(nex,-1);
	pro[1]=1;
	cin>>n;
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&u,&v);
		connect(u,v);
	}
	bfs.push(1);
	while(!bfs.empty())
	{
		i=bfs.front();	bfs.pop();	k=-1;
		if(fir[i]!=-1)
		{
			edge &g=e[fir[i]];
			pro[g.y]=pro[g.x]/con[g.x];
			ans=ans+pro[g.y];
			bfs.push(g.y);
			k=nex[fir[i]];
		}
		while(k!=-1)
		{
			edge &g=e[k];
			pro[g.y]=pro[g.x]/con[g.x];
			ans=ans+pro[g.y];
			bfs.push(g.y);
			k=nex[k];			
		}
	}
	printf("%.10lf\n",ans);
	return 0;
}