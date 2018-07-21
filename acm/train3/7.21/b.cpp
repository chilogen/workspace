#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e4+10,inf=1e15;
LL n,m,vis[maxn]={0},ans=0;
struct edge{
	LL from,to,w;
	edge(LL x,LL y,LL v){
		from=x;
		to=y;
		w=v;
	}
};
struct node{
	LL x,v;
}d[maxn];
struct cmp{
	bool operator()(node a,node b){
		return a.v>b.v;
	}
};
vector<edge>e;
vector<LL>v[maxn];
LL inpath[maxn],vise[2500010]={0};
priority_queue<node,vector<node>,cmp>q;
int dfs(LL x){
	if(inpath[x]!=-1)return inpath[x];
	inpath[x]=0;
	vector<LL>::iterator p=v[x].begin();
	if(x==n-1)return true;
	while(p!=v[x].end()){
		edge &te=e[*p];
		if(d[te.to].v!=d[te.from].v+te.w){p++;continue;}
		if(dfs(te.to)==1){
			if(!vise[*p]){
				vise[*p]=1;
				ans+=te.w;
			}
			inpath[x]=1;
		}
		p++;
	}
	return inpath[x];
}
void dfs2(LL x,LL f){
	if(x==n-1) return;
	vector<LL>::iterator p=v[x].begin();
	while(p!=v[x].end()){
		edge &te=e[*p];
		if(te.to==f){p++;continue;}
		if(!inpath[te.to]){p++;continue;}
		if(d[te.to].v!=d[te.from].v+te.w){p++;continue;}
		if(vise[*p]){p++;continue;}
		vise[*p]=1;
		ans+=te.w;
		dfs2(te.to,te.from);
		p++;
	}
}
void connect(LL x,LL y,LL k){
	v[x].push_back(e.size());
	e.push_back(edge(x,y,k));
}
int main(){
	LL i,j,k,l;
	cin>>n>>m;
	for(i=0;i<m;i++){
		scanf("%lld%lld%lld",&j,&k,&l);
		connect(j,k,l);
		connect(k,j,l);
	}
	for(i=0;i<maxn;i++){
		d[i].x=i;
		d[i].v=inf;
	}
	d[0].v=0;vis[0]=1;
	q.push(d[0]);
	while(!q.empty()){
		node tn=q.top();q.pop();
		vis[tn.x]=1;
		if(tn.v!=d[tn.x].v)continue;
		vector<LL>::iterator it=v[tn.x].begin();
		while(it!=v[tn.x].end()){
			edge &te=e[*it];it++;
			if(vis[te.to])continue;
			if(d[te.to].v>d[te.from].v+te.w){
				d[te.to].v=d[te.from].v+te.w;
				q.push(d[te.to]);
			}
		}
	}
	memset(vis,0,sizeof(vis));
	memset(inpath,-1,sizeof(inpath));
	inpath[n-1]=1;
	dfs(0);
	//dfs2(0,-1);
	cout<<ans*2<<endl;
	return 0;
}