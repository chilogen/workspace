#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e5+10;
LL dep[maxn]={0},a[maxn],ind[maxn];
vector<LL>g[maxn];
LL n;
void dfs(LL x,LL pre,LL d){
	vector<LL>::iterator it=g[x].begin();
	LL y;
	dep[x]=d;
	while(it!=g[x].end()){
		y=*it;it++;
		if(y==pre)continue;
		dfs(y,x,d+1);
	}
}
bool cmp(LL x,LL y){return ind[x]<ind[y];}
queue<LL>bfs;
vector<LL>tv,v;
int main(){
	LL i,j,k;
	cin>>n;
	for(i=1;i<n;i++){
		cin>>j>>k;
		g[j].push_back(k);
		g[k].push_back(j);
	}
	dfs(1,-1,1);
	for(i=0;i<n;i++){
		cin>>a[i];
		ind[a[i]]=i;
	}
	bfs.push(1);
	while(!bfs.empty()){
		tv.clear();
		k=bfs.front();bfs.pop();
		v.push_back(k);
		vector<LL>::iterator it=g[k].begin();
		while(it!=g[k].end()){
			j=*it;it++;
			if(dep[j]<dep[k])continue;
			tv.push_back(j);
		}
		sort(tv.begin(),tv.end(),cmp);
		it=tv.begin();
		while(it!=tv.end()){
			bfs.push(*it);
			it++;
		}
	}
	for(i=0;i<n;i++)if(v[i]!=a[i]){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	return 0;
}