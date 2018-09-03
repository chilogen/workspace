#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e5+10;
LL n,m,k,deg[maxn]={0},ans[maxn],tans;
bool vis[maxn]={0};
set<LL>g[maxn];
struct opera{
	LL x,y;
}p[maxn];
queue<LL>q;

void clean(){
	LL x,j;
	while(!q.empty()){
		x=q.front();q.pop();
		set<LL>::iterator it=g[x].begin();
		while(it!=g[x].end()){
			j=*it;it++;
			deg[j]--;
			if(vis[j])continue;
			if(deg[j]<k){
				q.push(j);
				vis[j]=1;
				tans--;
			}
		}
	}
}
int main(){
	LL i,j,l;
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(i=0;i<m;i++){
		cin>>j>>l;
		g[j].insert(l);
		g[l].insert(j);
		p[i]=(opera){l,j};
		deg[j]++;
		deg[l]++;
	}
	for(i=1;i<=n;i++){
		if(deg[i]>=k)tans++;
		else{
			vis[i]=1;
			q.push(i);
		}
	}
	clean();
	for(i=m-1;i>=0;i--){
		ans[i]=tans;
		if(vis[p[i].x]==1||vis[p[i].y]==1)continue;
		deg[p[i].x]--;
		deg[p[i].y]--;
		g[p[i].x].erase(p[i].y);
		g[p[i].y].erase(p[i].x);
		if(deg[p[i].x]<k){
			vis[p[i].x]=1;
			q.push(p[i].x);
			tans--;
		}
		if(deg[p[i].y]<k){
			vis[p[i].y]=1;
			q.push(p[i].y);
			tans--;
		}
		clean();
	}
	for(i=0;i<m;i++)cout<<ans[i]<<endl;
	return 0;
}