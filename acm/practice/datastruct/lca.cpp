#include <bits/stdc++.h>
using namespace std;
const int maxn=10000;
struct edge{
	int u,v,c;
	edge(int x,int y):u(x),v(y){}
};
vector<edge>e;
vector<int>ind[maxn];
void addedge(int x,int y){
	ind[x].push_back(e.size());
	e.push_back(edge(x,y));
}
struct lca{
	vector<int>vs,dep;
	int i=0;
	void dfs(int x,int from,int cl){
		vector<int>::iterator p=ind[x].begin();
		while(p!=ind[x].end){
			edge &te=e[*p];
			p++;
			if(te.v==from)continue;
			dfs(te.v,te.u,cl+1);
			if(i==0){
				vs.push_back(x);
				dep.push_back(cl);
			}
			i=1;
		}
	}
	int query(int x,int y){
		return vs[RMQ(x,y)];
	}
	int RMQ(int x,int y){
		
	}
}