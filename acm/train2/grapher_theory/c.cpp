#include <bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,cap,flow;
	edge(int a,int b,int c,int d):u(a),v(b),cap(c),flow(d){}
};
vector<edge>e;
vector<int>g[410];
int vis[50],d[50],n,m,row[30],col[30],ans[30][30];
inline void connect(int x,int y,int w){
	e.push_back(edge(x,y,w,0));
	e.push_back(edge(y,x,0,0));
	g[x].push_back(e.size()-2);
	g[y].push_back(e.size()-1);
}
inline bool bfs(){
	int i;
	memset(vis,0,sizeof(vis));vis[0]=1;
	memset(d,-1,sizeof(d));d[0]=0;
	queue<int>q;	q.push(0);
	while(!q.empty()){
		i=q.front();q.pop();
		vector<int>::iterator p=g[i].begin();
		while(p!=g[i].end()){
			edge &te=e[*p];
			if(!vis[te.v]&&te.cap>te.flow){
				vis[te.v]=1;
				d[te.v]=d[i]+1;
				if(te.v==n+m+1)return true;
				q.push(te.v);
			}
			p++;
		}
	}
	return false;
}
int dfs(int x,int y){
	vector<int>::iterator p=g[x].begin();
	if(y==0)return 0;
	if(x==n+m+1)return y;
	int f;
	while(p!=g[x].end()){
		edge &te=e[*p];
		edge &invte=e[(*p)^1];
		if(d[te.v]==d[x]+1&&(f=dfs(te.v,min(y,te.cap-te.flow)))!=0){
			te.flow+=f;
			invte.flow-=f;
			return f;
		}
		p++;
	}
	return 0;
}
inline bool check(){
	int i,j;
	vector<int>::iterator p;
	p=g[0].begin();
	while(p!=g[0].end()){
		edge &te=e[*p];
		if(te.flow!=te.cap)return false;
		p++;
	}
	p=g[n+m+1].begin();
	while(p!=g[n+m+1].end()){
		edge &te=e[(*p)^1];
		if(te.flow!=te.cap)return false;
		p++;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)ans[i-1][j-1]=1;
		p=g[i].begin();
		while(p!=g[i].end()){
			edge &te=e[*p];
			if(te.v!=0)ans[te.u-1][te.v-n-1]=te.flow+1;
			p++;
		}
	}
	return true;
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){cin>>row[i];row[i]-=m;}
	for(i=1;i<=m;i++){cin>>col[i];col[i]-=n;};
	for(i=1;i<=n;i++){
		connect(0,i,row[i]);
		for(j=1;j<=m;j++)connect(i,n+j,19);
	}
	for(i=1;i<=m;i++)connect(i+n,n+m+1,col[i]);
	while(bfs())
		dfs(0,999999);
	if(!check())cout<<"No\n";
	else{
		cout<<"Yes\n";
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}