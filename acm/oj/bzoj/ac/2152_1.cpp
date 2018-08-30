#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e5+10;

struct edge{LL to,w;};
vector<edge>e[maxn];

struct tripe{
	LL x,y,z;
	tripe(){x=y=z=0;}
	void shift(LL t){
		t%=3;
		int i;
		for(i=0;i<t;i++){
			swap(y,z);
			swap(x,y);
		}
	}
	void add(tripe a){
		this->x+=a.x;
		this->y+=a.y;
		this->z+=a.z;
	}
}f[maxn];

LL ans;

void dfs(LL x,LL from){
	vector<edge>::iterator it=e[x].begin();
	f[x].x=1;
	while(it!=e[x].end()){
		edge te=*it;it++;
		if(te.to==from)continue;
		dfs(te.to,x);
		tripe tp=f[te.to];
		tp.shift(te.w);
		ans+=2*(f[x].x*tp.x+f[x].y*tp.z+f[x].z*tp.y);
		f[x].add(tp);
	}
}

void solve(){
	LL i,j,k,u,v,w,n;
	cin>>n;
	for(i=0;i<n-1;i++){
		cin>>u>>v>>w;
		e[u].push_back((edge){v,w});
		e[v].push_back((edge){u,w});
	}
	ans=n;
	dfs(1,-1);
	k=n*n;j=__gcd(k,ans);
	cout<<ans/j<<"/"<<k/j<<endl;
}

int main(){
	solve();
	return 0;
}