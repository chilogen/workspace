#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
	vector<LL>upper;
	LL v;
}a[510];
LL ma[510],n,m,p,vis[510];
void connect(LL x,LL y){
	a[y].upper.push_back(x);
}
void sswap(LL x,LL y){
	LL i,j;
	i=ma[x];j=ma[y];
	swap(a[i].v,a[j].v);
	ma[x]=j;
	ma[y]=i;
}
LL query(LL x,LL ans,LL o){
	LL y=x;
	LL j;
	if(o==0)o++;
	else ans=min(ans,a[x].v);
	vector<LL>::iterator it=a[y].upper.begin();
	while(it!=a[y].upper.end()){
		j=*it;it++;
		if(vis[j])continue;
		vis[j]=1;
		ans=min(query(j,ans,o),ans);
	}
	if(ans>100)return -1;
	else return ans;
}
int main(){
	LL i,j,k;
	char c;
	cin>>n>>m>>p;
	for(i=1;i<=n;i++){
		cin>>j;
		a[i].v=j;
		ma[i]=i;
	}
	for(i=0;i<m;i++){
		cin>>j>>k;
		connect(j,k);
	}
	for(i=0;i<p;i++){
		cin>>c;
		if(c=='T'){
			cin>>j>>k;
			sswap(j,k);
		}
		if(c=='P'){
			cin>>j;
			memset(vis,0,sizeof(vis));
			if(a[ma[j]].upper.size()==0)k=-1;
			else k=query(ma[j],500,0);
			if(k==-1)cout<<"*\n";
			else cout<<k<<endl;
		}
	}
	return 0;
}