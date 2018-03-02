#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct edge
{
	LL u,v;
}e[400010];
LL fir[200010],nex[400010],vis[200010],edgenum=0;
inline void connect(LL a,LL b)
{
	e[edgenum].u=a;	e[edgenum].v=b;
	if(fir[a]!=-1)	nex[edgenum]=fir[a];
	fir[a]=edgenum;
	edgenum++;
}
int main()
{
	memset(fir,-1,sizeof(fir));
	memset(nex,-1,sizeof(nex));
	memset(vis,0,sizeof(vis));
	LL n,m,i,j,k,l,a,b;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		connect(a,b);
		connect(b,a);
	}
	queue<LL>bfs,deep;
	bfs.push(1);	deep.push(0);	vis[1]=1;
	while(!bfs.empty()&&!vis[n])
	{
		k=-1;i=bfs.front();	bfs.pop();
		j=deep.front();	deep.pop();
		if(j==2)	continue;
		if(i!=-1)
		{
			edge &g=e[fir[i]];
			if(!vis[g.v])
			{
				vis[g.v]=1;
				bfs.push(g.v);
				deep.push(j+1);
			}
			k=nex[fir[i]];
		}
		while(k!=-1)
		{
			edge &g=e[k];
			if(!vis[g.v])
			{
				vis[g.v]=1;
				bfs.push(g.v);
				deep.push(j+1);
			}
			k=nex[k];
		}
	}
	if(vis[n])	puts("POSSIBLE");
	else puts("IMPOSSIBLE");
	return 0;
}