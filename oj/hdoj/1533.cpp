#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
const Int maxn=1e5+10,Inf=1e15;
struct Edge{
	Int from,to,cap,flow,cost;
};
struct MCMF{
	Int n,m,s,t;
	vector<Edge>edges;
	vector<Int>G[maxn];
	Int inq[maxn],d[maxn],p[maxn],a[maxn];

	void init(Int n){
		Int i;
		this->n=n;
		for(i=0;i<n;i++)G[i].clear();
		edges.clear();
	}

	void AddEdge(Int from,Int to,Int cap,Int cost){
		G[from].push_back(edges.size());
		edges.push_back((Edge){from,to,cap,0,cost});
		G[to].push_back(edges.size());
		edges.push_back((Edge){to,from,0,0,-cost});
	}

	bool Bellmanford(Int s,Int t,Int &flow,Int &cost){
		Int i,u;
		for(i=0;i<n;i++)d[i]=Inf;
		memset(inq,0,sizeof(inq));
		d[s]=0;inq[s]=1;p[s]=0;a[s]=Inf;

		queue<Int>Q;
		Q.push(s);
		while(!Q.empty()){
			u=Q.front();Q.pop();
			inq[u]=0;
			for(i=0;i<(Int)G[u].size();i++){
				Edge &e=edges[G[u][i]];
				if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
					d[e.to]=d[u]+e.cost;
					p[e.to]=G[u][i];
					a[e.to]=min(a[u],e.cap-e.flow);
					if(!inq[e.to]){
						Q.push(e.to);
						inq[e.to]=1;
					}
				}
			}
		}
		if(d[t]==Inf)return false;
		flow+=a[t];
		cost+=d[t]*a[t];
		u=t;
		while(u!=s){
			edges[p[u]].flow+=a[t];
			edges[p[u]^1].flow-=a[t];
			u=edges[p[u]].from;
		}
		return true;
	}

	Int Mincost(Int s,Int t){
		Int flow=0,cost=0;
		while(Bellmanford(s,t,flow,cost));
		return cost;
	}
}solve;
char ma[110][110];
vector<pair<Int,Int>>hourse,humen;
Int n,m,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	Int i,j,k,l,s,t,dist;
	while(1){
		cin>>n>>m;
		humen.clear();hourse.clear();
		if(n+m==0)return 0;
		for(i=0;i<n;i++){
			cin>>ma[i];
			for(j=0;j<m;j++){
				if(ma[i][j]=='.')continue;
				if(ma[i][j]=='m')humen.push_back(make_pair(i,j));
				else hourse.push_back(make_pair(i,j));
			}
		}
		k=humen.size();l=hourse.size();
		s=0;t=k+l+1;
		solve.init(t+1);
		for(i=0;i<k;i++)solve.AddEdge(0,i+1,1,0);
		for(i=0;i<l;i++)solve.AddEdge(i+k+1,t,1,0);
		for(i=0;i<k;i++)for(j=0;j<l;j++){
			dist=abs(humen[i].first-hourse[j].first)+abs(humen[i].second-hourse[j].second);
			solve.AddEdge(i+1,j+1+k,1,dist);
		}
		cout<<solve.Mincost(s,t)<<endl;
	}
}