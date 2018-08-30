#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
const Int maxn=1e5+10,Inf=1e15,base=110;
struct Edge{
	Int from,to,cap,flow,cost;
};


vector<Int> aans;
Int n,k,t;

struct MCMF{
	Int n,m,s,t;
	vector<Edge>edges;
	vector<Int>G[maxn];
	Int inq[maxn],d[maxn],p[maxn],a[maxn];

	void update(){
		aans.clear();
		Int i,k,l;
		for(i=1;i<=n;i++){
			l=G[i].size();
			for(k=0;k<l;k++){
				Edge &te=edges[G[i][k]];
				if(te.flow==1&&te.cap==0){
				//if(te.cap==0){
					aans.push_back(te.to);
					break;
				}
			}
		}
	}

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
}solver;

Int a[510][20];


void solve(){
	Int i,j,l,ans=99999;
	cin>>n>>k>>t;
	for(i=1;i<=n;i++)for(j=1;j<=k+1;j++)cin>>a[i][j];

	for(i=1;i<=n;i++){
		solver.init(base+k+4);

		for(j=1;j<=n;j++){
			solver.AddEdge(0,j,1,0);
			for(l=1;l<=k+1;l++){
				solver.AddEdge(j,l+base,1,a[j][l]);
			}
		}

		for(l=1;l<=k;l++){
			if(l==t)continue;
			solver.AddEdge(l+base,base+k+2,i-1,0);
		}
		solver.AddEdge(t+base,base+k+3,i,0);
		solver.AddEdge(base+k+2,base+k+3,n-i,0);
		solver.AddEdge(k+1+base,k+base+2,n,0);
		l=solver.Mincost(0,base+k+3);
		if(l<ans){
			ans=l;
			solver.update();
		}
	}
	cout<<ans<<endl;
	cout<<aans.size();
	//for(i=0;i<n;i++)cout<<aans[i]<<" ";
}

int main(){
	solve();
	return 0;
}