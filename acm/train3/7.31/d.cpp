#include <bits/stdc++.h>
using namespace std;typedef long long LL;
const LL maxn=100,inf=1e8;
struct Edge{
	LL from,to,cap,flow;
};
struct Dinic{
	LL n,m,s,t;
	vector<Edge>edges;
	vector<LL>G[maxn];
	bool vis[maxn];
	LL d[maxn],cur[maxn];

	void init(){
		edges.clear();
		for(int i=0;i<maxn;i++)G[i].clear();
	}

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
int ind[2521],t,n,c[50] ,mark[48];
void init(){
	map<int,int>ma;
	LL i,j,k,cnt=0;
	for(i=1;i<=2520;i++){
		for(j=1,k=0;j<=10;j++){
			if(i%j==0){
				k^=1<<(j-1);
			}
		}
		if(ma.count(k)==0){
			ma[k]=cnt++;

		}
		ind[i]=ma[k];
		mark[ma[k]]=k;
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	init();
	LL i,j,k;
	cin>>t;
	while(t--){
		memset(c,0,sizeof(c));
		solve.init();
		cin>>n;
		k=n/2520;
		for(i=1;i<=2520;i++)c[ind[i]]+=k;
		for(i=1,k=n%2520;i<=k;i++)c[ind[i]]++;
		for(i=0;i<48;i++)solve.addedge(0,i+1,c[i]);
		for(i=1;i<=10;i++){
			cin>>k;
			for(j=0;j<48;j++){
				if(mark[j]&(1<<(i-1)))
					solve.addedge(j+1,i+50,k);
			}
			solve.addedge(i+50,70,inf);
		}
		cout<<solve.maxflow(0,70)<<endl;
	}
}