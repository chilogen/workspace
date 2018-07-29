#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e6+10,inf=1e15;
struct Edge{
	LL u,v,w;
};
struct node{
	LL x,w,f;
};
struct cmp{
	bool operator()(node a,node b){
		if(a.w==b.w)return a.f>b.f;
		else return a.w>b.w;
	}
};
vector<Edge>edges[maxn];
LL t,n,m,d[maxn],vis[maxn];
void init(){
	LL i;
	for(i=1;i<=n;i++){
		edges[i].clear();
	}
}
void dijkstra(){
	priority_queue<node,vector<node>,cmp>q;
	node tn;
	LL k;
	d[1]=0;q.push((node){1,0,1});
	while(!q.empty()){
		tn=q.top();q.pop();
		if(tn.w!=d[tn.x])continue;
		if(vis[tn.x])continue;
		vis[tn.x]=1;
		vector<Edge>::iterator e=edges[tn.x].begin();
		while(e!=edges[tn.x].end()){
			Edge te=*e;e++;
			k=max((LL)0,tn.f-te.w);
			if(d[te.v]>d[te.u]+k){
				d[te.v]=d[te.u]+k;
				q.push((node){te.v,d[te.v],max(te.w,tn.f)});
			}
		}
	}
}

LL inq[maxn],flag[maxn];
void spfa(){
	memset(inq,0,sizeof(inq));
	memset(flag,-1,sizeof(flag));
	queue<LL>bfs;
	d[1]=0;bfs.push(1);inq[1]=0;flag[1]=1;
	LL j,k;
	while(!bfs.empty()){
		j=bfs.front();bfs.pop();
		vector<Edge>::iterator e=edges[j].begin();
		while(e!=edges[j].end()){
			Edge te=*e;e++;
			k=max((LL)0,flag[j]-te.w);
			if(d[te.v]>d[te.u]+k){
				d[te.v]=d[te.u]+k;
				flag[te.v]=max((LL)1,te.w);
				if(!inq[te.v]){
					inq[te.v]=true;
					bfs.push(te.v);
				}
			}
		}
	}
}
int main(){
	LL i,j,k,l;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		memset(d,15,sizeof(d));
		memset(vis,0,sizeof(vis));
		if(t%2==0)init();
		for(i=0;i<m;i++){
			scanf("%lld%lld%lld",&j,&k,&l);
			edges[j].push_back((Edge){j,k,l});
			edges[k].push_back((Edge){k,j,l});
		}
		spfa();
		//dijkstra();
		printf("%lld\n",d[n]);
	}
	return 0;
}