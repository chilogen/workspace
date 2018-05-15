#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=3e5+10;
LL vis[maxn];
struct edge{
	LL u,v;
}e[2*maxn];
vector<LL>v[maxn];
LL n,x,y,num=0,cntx=0,cnty=0;
inline void conect(LL a,LL b){
	e[num].u=a;e[num].v=b;
	v[a].push_back(num++);
}
bool dfs1(LL k,LL last){
	if(k==y){
		vis[k]=1;
		cntx++;
		return true;
	}
	vector<LL>::iterator p=v[k].begin();
	while(p!=v[k].end()){
		edge &te=e[*p];
		if(te.v==last){p++;continue;}
		if(dfs1(te.v,te.u)){
			vis[te.u]=1;
			cntx++;
			return true;
		}
		p++;
	}
	return false;
}
void dfs2(LL k,LL last){
	cnty++;
	vector<LL>::iterator p=v[k].begin();
	while(p!=v[k].end()){
		edge &te=e[*p];
		if(te.v==last||vis[te.v]){p++;continue;}
		dfs2(te.v,te.u);
		p++;
	}
}
int main(){
	cin>>n>>x>>y;
	LL ans=n*(n-1),i,j,k;
	memset(vis,0,sizeof(vis));
	for(i=0;i<n-1;i++){
		scanf("%lld%lld",&j,&k);
		conect(j,k);
		conect(k,j);
	}
	dfs1(x,-1);
	dfs2(y,-1);
	cntx=cnty;
	cnty=0;
	dfs2(x,-1);
	cout<<ans-cntx*cnty<<endl;
	return 0;
}