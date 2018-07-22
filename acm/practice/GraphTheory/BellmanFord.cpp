#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct Edge{
	int from,to,dist;
	Edge(int x,int y,int z):from(x),to(y),dist(z){}
};
struct BellmanFord{
	int n,m;
	vector<Edge>edges;
	vector<int>G[maxn];
	bool inq[maxn];
	int d[maxn],cnt[maxn],p[maxn];

	void init(int n){
		this->n=n;
		int i;
		for(i=0;i<n;i++)G[i].clear();
		edges.clear();
	}

	void addedge(int from,int to,int dist){
		edges.push_back(Edge(from,to,dist));
		G[from].push_back(edges.size()-1);
	}

	int negativeCycle(){
		queue<int>Q;
		int i;
		memset(cnt,0,sizeof(cnt));
		for(i=1;i<= n;i++){
			d[i]=10000;
		}		
		d[1]=0;inq[1]=1;Q.push(1);
		while(!Q.empty()){
			i=Q.front();Q.pop();inq[i]=0;
			vector<int>::iterator it=G[i].begin();
			while(it!=G[i].end()){
				Edge &e=edges[*it];
				if(d[e.to]>d[e.from]+e.dist){
					d[e.to]=d[e.from]+e.dist;
					p[e.to]=e.from;
					if(!inq[e.to]){
						Q.push(e.to);
						cnt[e.to]++;
						inq[e.to]=1;
						if(cnt[e.to]>n)return e.to;
					}
				}
				it++;
			}
		}
		return -1;
	}
	void show(int x){
		if(x==-1){
			cout<<"do not have one\n";
			return;
		}
		int k=p[x];
		cout<<x<<" ";
		while(k!=x){
			cout<<k<<" ";
			k=p[k];
		}
	}
}bf;
int main(){
	int n,m,i,j,k,l;
	cin>>n>>m;
	bf.init(n);
	for(i=0;i<m;i++){
		cin>>j>>k>>l;
		bf.addedge(j,k,l);
		//bf.addedge(k,j,l);
	}
	bf.show(bf.negativeCycle());
	return 0;
}