#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e5+10;
struct edge{
	LL u,v,w;
	edge(LL a,LL b,LL c):u(a),v(b),w(c){}
};
vector<edge>e;
LL fat[maxn],ans=0,cnt=0,n,m;
bool cmp(edge a,edge b){return a.w<b.w;}
LL getfat(LL x){
	if(x==fat[x])return x;
	return fat[x]=getfat(fat[x]);
}

int main(){
	LL a,b,v,p,i,j,k,l;
	ios::sync_with_stdio(false);
	for(i=0;i<maxn;i++)fat[i]=i;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b>>v>>p;
		if(p==1)e.push_back(edge(a,b,v));
	}
	sort(e.begin(),e.end(),cmp);l=e.size();
	for(i=0;i<l;i++){
		j=getfat(e[i].u);k=getfat(e[i].v);
		if(j==k)continue;
		fat[k]=j;
		cnt++;ans+=e[i].w;
	}
	if(cnt!=n-1)cout<<"no\n";
	else cout<<"yes\n"<<ans<<endl;
	return 0;
}