#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct edge
{
	LL x,y,val;
};
vector<edge>e;
vector<LL>adj[3000000];
LL n,m,ind=0,dst[2000000],inf=1e15;
inline void connect(LL x,LL y,LL v)
{
	edge a;
	a.x=x,a.y=y,a.val=v;
	e.push_back(a);
	adj[x].push_back(ind++);
}
inline void input()
{
	LL i,j,x,y,v;
	cin>>n>>m;
	if(n==1||m==1)
	{
		for(i=1;i<max(m,n);i++)	cin>>dst[i];
		for(i=1;i<max(m,n);i++)	dst[1]=min(dst[1],dst[i]);
		cout<<dst[1]<<endl;
		exit(1);
	}
	for(i=1;i<=n;i++)
	for(j=1;j<m;j++)
	{
		cin>>v;
		x=(i-1)*(2*m-2)+2*j;
		y=x-(2*m-1);
		if(i==1)	y=n*m+1;
		else if(i==n)	x=0;
		connect(x,y,v);
		connect(y,x,v);
	}
	for(i=1;i<n;i++)
	for(j=1;j<=m;j++)
	{
		cin>>v;
		x=(i-1)*(2*m-2)+2*j-1;
		y=x-1;
		if(j==1)	y=0;
		else if(j==m)	x=n*m+1;
		connect(x,y,v);
		connect(y,x,v);
	}
	for(i=1;i<n;i++)
	for(j=1;j<m;j++)
	{
		cin>>v;
		x=(i-1)*(2*m-2)+2*j-1;
		y=x+1;
		connect(x,y,v);
		connect(y,x,v);
	}
	for(i=0;i<=n*m+1;i++)	dst[i]=inf;
	dst[0]=0;
}
inline LL find()
{
	LL p=0;
	vector<LL>::iterator q;
	q=adj[p].begin();
	while()	
}
int main()
{
	ios::sync_with_stdio(false);
	input();
	cout<<find()<<endl;
	return 0;
}