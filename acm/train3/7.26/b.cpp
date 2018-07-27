#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e5+10;
LL d[maxn];
struct edge{
	LL v,w;
};
struct node{
	LL x,w;
};
struct cmp{
	bool operator()(node a,node b){return a.w>b.w;}
};
LL n,m;
vector<edge>e[maxn];
priority_queue<node,vector<node>,cmp>q;
inline void connect(LL x,LL y,LL z){e[x].push_back((edge){y,z});}
void solve(LL x){
	vector<edge>::iterator it=e[x].begin();
	while(it!=e[x].end()){
		edge &te=*it;it++;
		if(d[te.v]<d[x]+te.w)continue;
		d[te.v]=d[x]+te.w;
		q.push((node){te.v,d[te.v]});
	}
}
int main(){
	LL i,j,k,l;
	node tn;
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>j>>k>>l;
		connect(j,k,2*l);
		connect(k,j,2*l);
	}
	for(i=1;i<=n;i++){
		cin>>d[i];
		q.push((node){i,d[i]});
	}
	while(!q.empty()){
		tn=q.top();q.pop();
		if(d[tn.x]!=tn.w)continue;
		solve(tn.x);
	}
	for(i=1;i<=n;i++)cout<<d[i]<<" ";
	return 0;
}