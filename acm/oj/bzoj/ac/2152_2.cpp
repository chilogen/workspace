//点分治

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=20010;
struct edge{
	LL to,v;
};
vector<edge>g[maxn];
LL root,maxson[maxn],son[maxn],d[maxn],f[3];
LL sum,ans,n;
bool vis[maxn];

void getroot(LL x,LL pre){
	son[x]=1;maxson[x]=0;
	vector<edge>::iterator it=g[x].begin();
	while(it!=g[x].end()){
		edge &te=*it;it++;
		if(vis[te.to]||te.to==pre)continue;
		getroot(te.to,x);
		son[x]+=son[te.to];
		maxson[x]=max(maxson[x],son[te.to]);
	}
	maxson[x]=max(maxson[x],sum-maxson[x]);
	if(maxson[x]<maxson[root])root=x;
}

void dfs(LL x,LL pre){
	f[d[x]%3]++;
	vector<edge>::iterator it=g[x].begin();
	while(it!=g[x].end()){
		edge &te=*it;it++;
		if(vis[te.to]||te.to==pre)continue;
		d[te.to]=d[x]+te.v;
		dfs(te.to,x);
	}
}

LL cal(LL x,LL nv){
	f[0]=f[1]=f[2]=0;
	d[x]=nv;
	dfs(x,-1);
	return f[0]*f[0]+2*f[1]*f[2];
}

void work(LL x){
	vis[x]=1;
	ans+=cal(x,0);
	vector<edge>::iterator it=g[x].begin();
	while(it!=g[x].end()){
		edge &te=*it;it++;
		if(vis[te.to])continue;
		ans-=cal(te.to,te.v);
		root=0;sum=son[te.to];
		getroot(te.to,-1);
		work(root);
	}
}

void solve(){
	cin>>n;
	LL i,j,k,l;
	for(i=1;i<n;i++){
		cin>>j>>k>>l;
		g[j].push_back((edge){k,l});
		g[k].push_back((edge){j,l});
	}
	sum=n;maxson[1]=maxson[0]=maxn;
	getroot(1,-1);
	work(root);
	l=__gcd(ans,n*n);
	cout<<ans/l<<"/"<<n*n/l<<endl;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	solve();return 0;
}
