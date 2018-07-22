/*
	* directional road, if want to change, focuse on:
		* dfs1->while
	  	* use connect() double time,  
		* change maxn
*/

#include <bits/stdc++.h>
using namespace std;
typedef int Int;
const Int maxn=10000;
Int son[maxn]={0},deepth[maxn],size[maxn],idx[maxn],fat[maxn];
Int cnt=0,a[maxn],b[maxn],top[maxn];
struct edge{
	Int u,v;
	edge(Int x,Int y):u(x),v(y){}
};
vector<edge>e;
vector<Int>ind[maxn];
map<Int,Int>m;
void connect(Int x,Int y){
	ind[x].push_back(e.size());
	e.push_back(edge(x,y));
}
Int dfs1(Int x,Int f,Int d){
	deepth[x]=d;
	fat[x]=f;
	size[x]=1;
	Int mson=-1;
	vector<Int>::iterator p=ind[x].begin();
	while(p!=ind[x].end()){
		edge &te=e[*p];p++;
		size[x]+=dfs1(te.v,te.u,d+1);
		if(size[te.v]>mson){
			mson=size[te.v];
			son[x]=te.v;
		}
	}
	return size[x];
}
void dfs2(Int x,Int topf){
	idx[x]=++cnt;
	a[cnt]=b[x];	//node val
	m[x]=cnt;
	top[cnt]=topf;
	if(son[x]==0)return;
	dfs2(son[x],topf);
	vector<int>::iterator p=ind[x].begin();
	while(p!=ind[x].end()){
		edge &te=e[*p];p++;
		if(te.v==son[x])continue;
		dfs2(te.v,te.v);
	}
}
int main(){
	Int n,i,j,k;
	cin>>n;
	for(i=0;i<n-1;i++){
		cin>>j>>k;
		connect(min(j,k),max(j,k));
	}
	dfs1(1,-1,0);
	dfs2(1,1);
	cout<<"son :\n";
	for(i=1;i<=n;i++)cout<<son[i]<<" ";
	cout<<"\ntop father:\n";
	for(i=1;i<=n;i++)cout<<top[i]<<" ";
	cout<<"\nsize\n";
	for(i=1;i<=n;i++)cout<<size[i]<<" ";
	cout<<"\nMap\n";
	for(i=1;i<=n;i++)cout<<m[i]<<" ";
	return 0;
}