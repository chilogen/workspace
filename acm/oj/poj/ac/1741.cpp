//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn=10010;

struct edge{LL to,v;};
vector<edge>g[maxn];

bool vis[maxn];
LL son[maxn],maxson[maxn],f[maxn];
LL sum,root,ans,n,k;

void getroot(LL x,LL pre){
	vector<edge>::iterator it=g[x].begin();
	son[x]=1;maxson[x]=0;
	while(it!=g[x].end()){
		edge &te=*it;it++;
		if(vis[te.to]||pre==te.to)continue;
		getroot(te.to,x);
		son[x]+=son[te.to];
		maxson[x]=max(maxson[x],son[te.to]);
	}
	maxson[x]=max(maxson[x],sum-maxson[x]);
	if(maxson[x]<maxson[root])root=x;
}

void dfs(LL x,LL d,LL pre){
	if(d>k)return;
	vector<edge>::iterator it=g[x].begin();
	f[++f[0]]=d;
	while(it!=g[x].end()){
		edge &te=*it;it++;
		if(vis[te.to]||pre==te.to)continue;
		dfs(te.to,d+te.v,x);
	}
}

LL cal(LL x,LL nd){
	f[0]=0;
	dfs(x,nd,-1);
	sort(f+1,f+1+f[0]);
	LL l=1,r=f[0],ans=0;
	while(l<r){
		if(f[l]+f[r]<=k){
			ans+=(r-l);
			l++;
		}
		else r--;
	}
	return ans;
}

void work(LL x){
	ans+=cal(x,0);
	vis[x]=1;
	vector<edge>::iterator it=g[x].begin();
	while(it!=g[x].end()){
		edge &te=*it;it++;
		if(vis[te.to])continue;
		ans-=cal(te.to,te.v);
		sum=son[te.to];root=0;
		getroot(te.to,-1);
		work(root);
	}
}

void solve(){
	LL i,j,l,m;
	for(i=0;i<=n;i++)g[i].clear();
	memset(vis,0,sizeof(vis));
	ans=0;
	for(i=1;i<n;i++){
		cin>>j>>l>>m;
		g[j].push_back((edge){l,m});
		g[l].push_back((edge){j,m});
	}
	root=0;maxson[0]=sum=n;
	getroot(1,-1);
	work(root);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	while(1){
		cin>>n>>k;
		if(n+k==0)return 0;
		solve();
		cout<<ans<<endl;
	}
}