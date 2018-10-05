#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1001;
LL n,m,s,e,k,t,dist[maxn],cnt[maxn],cntinv[maxn];
struct node{
	LL x,v,f;
};
struct edge{
	LL to,v;
}g[maxn][maxn],inv[maxn][maxn];
struct cmp{
	bool operator()(node a,node b){
		return a.v>b.v;
	}
};
struct cmp1{
	bool operator()(node a,node b){
		return a.f>b.f;
	}
};

inline void dijk(){
	LL i;
	priority_queue<node,vector<node>,cmp>q;
	memset(dist,1,sizeof(LL)*(n+1));
	dist[e]=0;
	q.push((node){e,0,0});
	while(!q.empty()){
		node tn=q.top();q.pop();
		if(tn.v!=dist[tn.x])continue;
		for(i=0;i<cntinv[tn.x];i++){
			if(dist[g[tn.x][i].to]>dist[tn.x]+g[tn.x][i].v){
				dist[g[tn.x][i].to]=dist[tn.x]+g[tn.x][i].v;
				q.push((node){g[tn.x][i].to,dist[g[tn.x][i].to],0});
			}
		}
	}
}



LL solve(){
	priority_queue<node,vector<node>,cmp1>q;
	cin>>s>>e>>k>>t;
	LL i,j,l,d;
	for(i=0;i<=n;i++)cnt[i]=cntinv[i]=0;
	for(i=0;i<m;i++){
		cin>>j>>l>>d;
		g[j][cnt[j]++]=(edge){l,d};
		inv[l][cntinv[l]++]=(edge){j,d};
	}
	dijk();
	q.push((node){s,0,dist[s]});
	while(!q.empty()){
		node tn=q.top();q.pop();
		if(tn.x==e){
			k--;
			if(k==0)return tn.v;
		}
		for(i=0;i<cnt[tn.x];i++){
			q.push((node){g[tn.x][i].to,g[tn.x][i].v+tn.v,g[tn.x][i].v+tn.v+dist[g[tn.x][i].to]});
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	LL x;
	while(cin>>n>>m){
		x=solve();
		if(x<=t)cout<<"yareyaredawa\n";
		else cout<<"Whitesnake!\n";
	}
	return 0;
}