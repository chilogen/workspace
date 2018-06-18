#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1010;
const LL inf=1e17;
LL n,m,k,h[maxn],st,en;
struct edge{
	LL u,v,d;
	edge(LL a,LL b,LL c):u(a),v(b),d(c){}
};
vector<edge>e0,e1;
vector<LL>ind0[maxn],ind1[maxn];
struct node{
	LL x,d,g;
};
node makenode(LL a,LL b,LL c){
	node t;
	t.x=a;t.d=b;t.g=c;
	return t;
}
struct cmp{
	bool operator()(node a,node b){return a.g>b.g;}
};
priority_queue<node,vector<node>,cmp>q;
void connect(LL x,LL y,LL z){
	e0.push_back(edge(x,y,z));
	ind0[x].push_back(e0.size()-1);
	e1.push_back(edge(y,x,z));
	ind1[y].push_back(e1.size()-1);
}
void dijkstra(LL s){
	pair<LL,LL>tp;
	LL i;
	for(i=0;i<maxn;i++)h[i]=inf;
	h[s]=0;
	priority_queue<pair<LL,LL>>tq;
	tq.push(make_pair(0,s));
	while(!tq.empty()){
		tp=tq.top();tq.pop();
		if(tp.first!=h[tp.second])continue;
		vector<LL>::iterator p=ind1[tp.second].begin();
		while(p!=ind1[tp.second].end()){
			edge &te=e1[*p];
			if(h[te.v]>h[te.u]+te.d){
				h[te.v]=h[te.u]+te.d;
				tq.push(make_pair(h[te.v],te.v));
			}
			p++;
		}
	}
}
LL solve(){
	if(h[st]==inf)return -1;
	LL j;
	q.push(makenode(st,0,h[st]));
	j=0;
	node tno;
	while(!q.empty()){
		node no=q.top();q.pop();
		if(no.x==en)j++;
		if(j==k)return no.d;
		vector<LL>::iterator p=ind0[no.x].begin();
		while(p!=ind0[no.x].end()){
			edge &te=e0[*p];p++;
			tno=makenode(te.v,no.d+te.d,no.d+h[te.v]+te.d);
			if(tno.g>=inf)continue;
			q.push(tno);
		}
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	LL i,x,y,z;
	cin>>n>>m>>k>>st>>en;
	for(i=0;i<m;i++){
		cin>>x>>y>>z;
		connect(x,y,z);
	}
	dijkstra(en);
	if(st==en)k++;
	cout<<solve()<<endl;
	return 0;
}