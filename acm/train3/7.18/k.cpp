#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=1010;
struct node{
	int x,v;
	node(int a,int b):x(a),v(b){}
};
struct cmp{
	bool operator()(node a,node b){return a.v>b.v;}
};
int n,m,T,s,t;
int a[maxn],dist[maxn],e[maxn][maxn],vis[maxn];
vector<int>ind[maxn];
priority_queue<node,vector<node>,cmp>bfs;

void connect(int x,int y,int c){
	ind[y].push_back(x);
	ind[x].push_back(y);
	e[x][y]=e[y][x]=c;
}
int main(){
	int i,j,k,l,o,p;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(e,0,sizeof(e));
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			ind[i].clear();
			dist[i]=1e9;
		}
		for(i=0;i<m;i++){
			scanf("%d%d%d",&j,&k,&l);
			connect(j,k,l);
		}
		scanf("%d%d",&s,&t);
		bfs.push(node(s,0));
		dist[s]=0;a[t]=0;
		while(!bfs.empty()){
			node nn=bfs.top();bfs.pop();
			if(nn.x==t)continue;
			if(nn.v!=dist[nn.x])continue;
			if(vis[nn.x])continue;
			vis[nn.x]=1;
			o=ind[nn.x].size();
			for(p=0;p<o;p++){
				i=ind[nn.x][p];
				if(vis[i])continue;
				l=nn.v+e[nn.x][i];
				if(a[i]!=0){
					j=(l)/a[i];
					if(j%2!=0){
						j-=j%2;
						j+=2;
						l+=(a[i]*j-l);
					}
				}
				if(l>=dist[i])continue;
				bfs.push(node(i,l));
				dist[i]=l;
			}
		}
		printf("%d\n",dist[t]);
	}
	return 0;
}