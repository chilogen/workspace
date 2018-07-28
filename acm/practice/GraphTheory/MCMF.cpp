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
};
int main(){}