#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5,inf=1e8;
struct Edge{
	LL from,to,cap,flow;
};
struct Dinic{
	LL n,m,s,t;
	vector<Edge>edges;
	vector<LL>G[maxn];
	bool vis[maxn];
	LL d[maxn],cur[maxn];

	bool bfs(){
		memset(vis,0,sizeof(vis));
		queue<LL>Q;
		Q.push(s);
		d[s]=0;vis[s]=1;
		while(!Q.empty()){
			LL x=Q.front();Q.pop();
			for(LL i=0;i<(LL)G[x].size();i++){
				Edge &e=edges[G[x][i]];
				if(!vis[e.to]&&e.cap>e.flow){
					vis[e.to]=1;
					d[e.to]=d[x]+1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}
	LL dfs(LL x,LL a){
		if(x==t||a==0)return a;
		LL flow=0,f;
		for(LL &i=cur[x];i<(LL)G[x].size();i++){
			Edge &e=edges[G[x][i]];
			if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
				e.flow+=f;
				edges[G[x][i]^1].flow-=f;
				flow+=f;
				a-=f;
				if(a==0)break;
			}
		}
		return flow;
	}
	LL maxflow(LL s,LL t){
		this->s=s;this->t=t;
		LL flow=0;
		while(bfs()){
			memset(cur,0,sizeof(cur));
			flow+=dfs(s,inf);
		}
		return flow;
	}
	void addedge(LL from,LL to,LL cap){
		G[from].push_back(edges.size());
		edges.push_back((Edge){from,to,cap,0});
		G[to].push_back(edges.size());
		edges.push_back((Edge){to,from,0,0});
	}
}solve;
int main(){
	LL n,m,i,j,k,x,y;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		j=i*2;
		k=j^1;
		solve.addedge(1,j,1);
		solve.addedge(k,2*(n+1),1);
	}
	for(i=0;i<m;i++){
		scanf("%lld%lld",&x,&y);
		x++;y++;
		x*=2;y*=2;x^=1;
		solve.addedge(y,x,1);
	}
	//k=solve.maxflow(1,2*n+2);
	cout<<(solve.maxflow(1,2*n+2)==n?"YES\n":"NO\n");
	return 0;
}
