#include <bits/stdc++.h>
using namespace std;
int Case,n,m,t,fat[30],vis[500],ans;
struct edge{
	int u,v,w;
	edge(){}
	edge(int a,int b,int c):u(a),v(b),w(c){}
};
bool cmp(edge a,edge b){return a.w<b.w;}
vector<edge>e;
int getfat(int x){
	if(x==fat[x])return x;
	return fat[x]=getfat(fat[x]);
}
int main(){
	int i,j,k,l;
	cin>>t;
	for(Case=1;Case<=t;Case++){
		cin>>n>>m;
		e.clear();
		memset(vis,0,sizeof(vis));
		ans=0;
		for(i=0;i<30;i++)fat[i]=i;
		for(i=0;i<m;i++){
			cin>>j>>k>>l;
			e.push_back(edge(j,k,l));
			e.push_back(edge(k,j,l));
		}
		sort(e.begin(),e.end(),cmp);
		m=e.size();
		for(i=0;i<m;i++){
			if(vis[i]||vis[i^1])continue;
			edge &te=e[i];
			j=getfat(e[i].u);k=getfat(e[i].v);
			vis[i]=vis[i^1]=1;
			if(j==k)continue;
			ans+=te.w;
			fat[j]=k;
		}
		cout<<"Case #"<<Case<<": "<<ans<<" meters\n";
	}
	return 0;
}