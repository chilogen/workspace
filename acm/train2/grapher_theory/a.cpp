#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e5+10;
vector<pair<LL,LL> >e;
vector<LL>v[maxn];
LL n,k,m,d[maxn];
inline void connect(LL a,LL b){
	v[b].push_back(e.size());
	e.push_back(make_pair(b,a));
}
LL dfs(LL x){
	if(v[x].size()==0)return 1;
	if(d[x]!=-1)return d[x];
	d[x]=maxn;
	vector<LL>::iterator p=v[x].begin();
	while(p!=v[x].end()){
		pair<LL,LL>tp=e[*p];
		d[x]=min(d[x],dfs(tp.second)+1);
		p++;
	}
	return d[x];
}
int main(){
	memset(d,-1,sizeof(d));
	LL i,a,b;
	cin>>n>>k>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		connect(a,b);
	}
	cout<<dfs(k)<<endl;
	return 0;
}
/*
......
*/