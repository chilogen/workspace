#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10,inf=1e18;
struct edge{
	LL to,w;
};
struct node{
	LL v,rk,d;
};
struct cmp{
	bool operator()(node a,node b){return a.d>b.d;}
};

vector<edge>g[maxn];
LL n,m,k;
LL dist[maxn][11];

void solve(){
	cin>>n>>m>>k;
	LL i,j,u,v,w;
	node tn;
	for(i=1;i<=n;i++){
		g[i].clear();
		for(j=0;j<=k;j++)dist[i][j]=inf;
	}
	for(i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back((edge){v,w});
	}
	priority_queue<node,vector<node>,cmp>dijk;
	dijk.push((node){1,k,0});dist[1][k]=0;
	while(!dijk.empty()){
		tn=dijk.top();dijk.pop();
		if(dist[tn.v][tn.rk]!=tn.d)continue;
		vector<edge>::iterator it=g[tn.v].begin();
		while(it!=g[tn.v].end()){
			edge &te=*it;it++;
			if(dist[te.to][tn.rk]>dist[tn.v][tn.rk]+te.w){
				dist[te.to][tn.rk]=dist[tn.v][tn.rk]+te.w;
				dijk.push((node){te.to,tn.rk,dist[te.to][tn.rk]});
			}
			if(tn.rk>0&&dist[te.to][tn.rk-1]>dist[tn.v][tn.rk]){
				dist[te.to][tn.rk-1]=dist[tn.v][tn.rk];
				dijk.push((node){te.to,tn.rk-1,dist[te.to][tn.rk-1]});
			}
		}
	}
	for(i=0,j=inf;i<=k;i++)j=min(j,dist[n][i]);
	cout<<j<<endl;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}