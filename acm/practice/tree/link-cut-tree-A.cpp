#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
const Int maxn=1e4;
struct Edge{
	Int u,v,w;
};
struct linkcutree{
	Int dep[maxn],fat[maxn],size[maxn],son[maxn];	//fill in dfs1
	Int top[maxn],idx[maxn];						//fill in dfs2

	Int val[maxn];									//node val

	Int cnt;
	vector<Edge>edges[maxn];

	void connect(Int x,Int y,Int z){
		edges[x].push_back((Edge){x,y,z});
	}

	Int dfs1(Int x,Int f){
		fat[x]=f;dep[x]=dep[f]+1;
		size[x]=1;son[x]=-1;
		Int maxson=-1;
		vector<Edge>::iterator e=edges[x].begin();
		while(e!=edges[x].end()){
			size[x]+=dfs1(e->v,e->u);
			if(size[e->v]>maxson){
				maxson=size[e->v];
				son[x]=e->v;
			}
			e++;
		}
		return size[x];
	}

	void dfs2(Int x,Int topf){
		idx[x]=++cnt;top[x]=topf;
		if(son[x]==-1)return;
		dfs2(son[x],topf);
		vector<Edge>::iterator e=edges[x].begin();
		while(e!=edges[x].end()){
			if(e->v==son[x]){e++;continue;}
			dfs2(e->v,e->v);
			e++;
		}
	}

	Int LCA(Int x,Int y){
		dep[1]=-1;
		dfs1(1,1);
		dfs2(1,1);
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			x=fat[top[x]];
		}
		if(dep[x]<dep[y])return x;
		return y;
	}
}solve;
int main(){
	Int n,i,j,k;
	cin>>n;
	for(i=0;i<n-1;i++){
		cin>>j>>k;
		solve.connect(j,k,0);
	}
	cout<<solve.LCA(4,5)<<endl;
	return 0;
}
