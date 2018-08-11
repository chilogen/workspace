//TLE
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAXN 200010
struct edge{
	LL u,v,w;
}te;
struct cost{
	LL c,city;
}tc;
bool cmp(cost a,cost b){
	return a.c<b.c;
}
vector<edge>e[MAXN];
vector<cost>v,v1;
LL n,m;
void bfs(LL x){
	LL i,j,k;
	vector<edge>::iterator p;
	queue<LL>q;
	q.push(x);
	while(!q.empty()){
		i=q.front();	q.pop();
		p=e[i].begin();
		while(p!=e[i].end()){
			te=*p;
			if(v[te.v-1].c>v[te.u-1].c+2*te.w){
				v[te.v-1].c=v[te.u-1].c+2*te.w;
				q.push(te.v);
			}
			p++;
		}
	}
}
int main(){
	int i,j,k;
	cin>>n>>m;
	for(i=0;i<m;i++){
		scanf("%lld%lld%lld",&te.u,&te.v,&te.w);
		e[te.u].push_back(te);
		te.u^=te.v;te.v^=te.u;te.u^=te.v;
		e[te.u].push_back(te);
	}
	for(i=1;i<=n;i++){
		cin>>tc.c;
		tc.city=i;
		v.push_back(tc);
	}
	v1=v;
	sort(v1.begin(),v1.end(),cmp);
	for(i=0;i<n;i++){
		bfs(v1[i].city);
	}
	for(i=0;i<n;i++){
		cout<<v[i].c<<" ";
	}
	cout<<endl;
	return 0;
}