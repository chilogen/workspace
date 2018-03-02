#include <bits/stdc++.h>
#define INF 1000000000
#define MAXN 100010
#define pb push_back
using namespace std;
struct edge{
	int u,v,w;
};
vector<int>v[MAXN];
vector<edge>e;
int n,m,s,t,dst[MAXN];
bool vis[MAXN]={0};
void Dijkstra_vertex(){
	int i,j,k,x,Min=INF;
	vector<int>::iterator p;
	for(j=0;j<n;j++){
		for(i=1;i<=n;i++){
			if(!vis[i]&&dst[i]<Min)	x=i;
		}
		vis[x]=1;
		p=v[x].begin();
		while(p!=v[x].end()){
			edge  &te=e[*p];
			if(dst[te.u]+te.w<dst[te.v])	dst[te.v]=dst[te.u]+te.w;
			p++;
		}
	}
}
void Dijkstra_edge(){

}
int main(){
	int i,j,k;
	cin>>n>>m;
	for(i=0;i<m;i++){
		edge te;
		cin>>te.u>>te.v>>te.w;
		v[te.u].pb(e.size());	e.pb(te);
	}
	cin>>s>>t;
	
	for(i=0;i<MAXN;i++)	dst[i]=INF;
	dst[s]=0;
	Dijkstra_vertex();
	for(i=1;i<=n;i++)	cout<<dst[i]<<" ";
	cout<<endl<<endl;

	/*for(i=0;i<MAXN;i++)	dst[i]=INF,vis[i]=0;
	dst[s]=0;	vis[s]=1;
	Dijkstra_edge();
	for(i=1;i<=n;i++)	cout<<dst[i]<<" ";
	cout<<endl<<endl;*/
	return 0;
}