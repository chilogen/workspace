//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
#define Maxn 100000
typedef long long LL;
LL Inf=1e18;
struct edge{
	LL u,v,flow;
};
edge make_edge(LL x,LL y,LL z){
	edge te;
	te.u=x;te.v=y;te.flow=z;
	return te;
}
vector<LL>ind[Maxn];
vector<edge>e;
LL lev[Maxn],n,m,ans;
bool bfs(){
	LL i,j,k;
	queue<LL>q;
	memset(lev,-1,sizeof(lev));
	q.push(1);lev[1]=0;
	while(!q.empty()){
		i=q.front();q.pop();
		vector<LL>::iterator p=ind[i].begin();
		while(p!=ind[i].end()){
			edge &te=e[*p];
			if(lev[te.v]==-1&&te.flow!=0){
				q.push(te.v);
				lev[te.v]=lev[te.u]+1;
			}
			p++;
		}
	}
	return lev[n]!=-1;
}
LL dfs(LL x,LL y){
	if(x==n){
		ans+=y;
		return y;
	}
	LL tf;
	vector<LL>::iterator p=ind[x].begin();
	while(p!=ind[x].end()){
		edge &te=e[*p];
		if(lev[te.v]==lev[te.u]+1&&te.flow!=0){
			tf=dfs(te.v,min(te.flow,y));
			if(tf!=-1){
				te.flow-=tf;
				return tf;
			}
		}
		p++;
	}
	return -1;
}
int main(){
	LL i,j,k,l,x,y,z;
	while(scanf("%lld%lld",&m,&n)!=EOF){
		e.clear();
		for(i=0;i<=n;i++)ind[i].clear();
		ans=0;
		for(i=0;i<m;i++){
			cin>>x>>y>>z;
			e.push_back(make_edge(x,y,z));
			ind[x].push_back(e.size()-1);
		}
		while(bfs()){
			dfs(1,Inf);
		}
		cout<<ans<<endl;
	}
	return 0;
}
