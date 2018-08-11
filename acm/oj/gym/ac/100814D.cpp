#include <bits/stdc++.h>
#define reset(a,b)	memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
LL INF=1e13;
struct edge
{
	LL u,v,w;
}e[100010];
LL fir[100010],nex[100010],edge_num=0,ti[100010],mi[100010],d;
vector<LL>	ans;
inline void connect(LL a,LL b,LL c)
{
	e[edge_num].u=a;
	e[edge_num].v=b;
	e[edge_num].w=c;
	if(fir[a]!=-1)	nex[edge_num]=fir[a];
	fir[a]=edge_num;
	edge_num++;
}
queue<LL>bfs;
int main()
{
	LL t,n,a,b,i,j,k,l,q;
	cin>>t;
	while(t--)
	{
		cin>>n;
		reset(fir,-1);	reset(nex,-1);	edge_num=0;
		for(i=1;i<=n;i++)	mi[i]=INF;
		for(i=2;i<=n;i++)
		{
			cin>>j>>k;
			connect(j,i,k);
			mi[j]=min(mi[j],k);
		}
		bfs.push(1);
		while(!bfs.empty())
		{
			i=bfs.front();	bfs.pop();
			j=mi[i];	k=-1;
			if(fir[i]==-1)	ans.push_back(ti[i]);
			if(fir[i]!=-1)
			{
				k=nex[fir[i]];
				edge &g=e[fir[i]];
				if(g.w>j)	ti[g.v]=ti[g.u]+j+2*(g.w-j);
				else ti[g.v]=ti[g.u]+j;
				bfs.push(g.v);
			}
			while(k!=-1)
			{
				edge &g=e[k];
				if(g.w>j)	ti[g.v]=ti[g.u]+j+2*(g.w-j);
				else ti[g.v]=ti[g.u]+j;
				bfs.push(g.v);
				k=nex[k];
			}
		}
		ans.push_back(0);
		sort(ans.begin(),ans.end());
		cin>>q;
		d=ans.size();
		LL s1,e1,m1;
		for(i=0;i<q;i++)
		{
			cin>>j;
			if(j>=ans[d-1])
			{
				cout<<d-1<<endl;
				continue;
			}
			s1=0;	e1=d-1;
			while(1)
			{
				m1=(s1+e1)>>1;
				if(s1==m1)
				{
					cout<<m1<<endl;
					break;
				}
				if(ans[m1]<j)
				{
					s1=m1;
					continue;
				}
				else if(ans[m1]>j)
				{
					e1=m1;
					continue;
				}
				if(ans[m1]==ans[e1])
				{
					cout<<e1<<endl;
					break;
				}
				if(ans[m1]==ans[m1+1])
				{
					s1=m1+1;
					continue;
				}
				if(ans[m1]<=j&&ans[m1+1]>=j)
				{
					cout<<m1<<endl;
					break;
				}
			}
		}
		ans.clear();
	}
	return 0;
}