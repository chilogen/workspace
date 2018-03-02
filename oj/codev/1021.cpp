#include <bits/stdc++.h>
using namespace std;
#define reset(a,b)	memset(a,b,sizeof(a))
typedef long long	LL; 
struct edge
{
	LL u,v,w;
};
const LL INF=(LL)1<<62;
edge e[500000];
LL n,m,dst1[1010],dstn[1010],fir[1010],nex[500000];
void spfa(LL *dst,LL x)
{
	queue<LL>q;
	LL i,j,k,l;
	q.push(x);
	while(!q.empty())
	{
		i=q.front();	q.pop();
		j=fir[i];	k=nex[j];
		if(dst[e[j].v]>dst[i]+e[j].w)
		{
			dst[e[j].v]=dst[i]+e[j].w;
			q.push(e[j].v);
		}
		while(k!=-1)
		{
			if(dst[e[k].v]>dst[i]+e[k].w)
			{
				dst[e[k].v]=dst[i]+e[k].w;
				q.push(e[k].v);
			}
			k=nex[k];
		}
	}
}
LL p1(LL x,LL del)
{
	LL i,j,k,l;
	i=fir[x];	k=nex[i];
	j=INF;
	if(e[i].v!=del&&dst1[e[i].u]<=dst1[e[i].v]&&dstn[e[i].u]>=dstn[e[i].v])	j=dst1[e[i].u]+dstn[e[i].v]+e[i].w;
	while(k!=-1)
	{
		if(e[k].v!=del&&dst1[e[k].u]<=dst1[e[k].v]&&dstn[e[k].u]>=dstn[e[k].v])	j=min(j,dst1[e[k].u]+dstn[e[k].v]+e[k].w);
		k=nex[k];
	}
	return j;
}
int main()
{
	LL i,j,l,mi,ma,tmp;
	cin>>n>>m;
	for(i=1;i<=n;i++)	dst1[i]=dstn[i]=INF;
	dst1[1]=dstn[n]=0;
	reset(fir,-1);	reset(nex,-1);
	for(i=0;i<m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
		if(fir[e[i].u]!=-1)
			nex[i]=fir[e[i].u];
		fir[e[i].u]=i;
		e[i+m].u=e[i].v;	e[i+m].v=e[i].u;	e[i+m].w=e[i].w;
		if(fir[e[i+m].u]!=-1)
			nex[i+m]=fir[e[i+m].u];
		fir[e[i+m].u]=i+m;
	}
	spfa(dst1,1);	spfa(dstn,n);
	mi=dst1[n];	ma=-1;
	for(i=0;i<m;i++)
	{
		if(dst1[e[i].u]+dstn[e[i].v]+e[i].w==mi)	ma=max(ma,p1(e[i].u,e[i].v));
		else if(dst1[e[i].v]+dstn[e[i].u]+e[i].w==mi)	ma=max(ma,p1(e[i].v,e[i].u));
	}
	cout<<ma<<endl;
	return 0;
}