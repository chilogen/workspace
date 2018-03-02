

#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;
struct edge{
	int u,v;
}e[MAXN*4];
vector<int>v[MAXN];
bool vis[MAXN]={0};
int n,m,l,s,t,dst[MAXN],num=0;
void bfs(int x){
	int i,j,k;
	queue<int>q;
	vector<int>::iterator p;
	memset(dst,-1,sizeof(dst));
	dst[x]=0;
	q.push(x);
	while(!q.empty()){
		i=q.front();	q.pop();
		if(dst[i]==l)	break;
		p=v[i].begin();
		while(p!=v[i].end()){
			edge &te=e[*p];
			if(dst[te.v]==-1){
				dst[te.v]=dst[te.u]+1;
				q.push(te.v);
			}
			p++;
		}
	}
}
bool dfs(int x,int d){
	if(x==t&&d==l)	return 1;
	if(x==t||d+dst[x]>l)	return 0;
	vector<int>::iterator p=v[x].begin();
	while(p!=v[x].end()){
		edge &te=e[*p];
		if(vis[te.v]){p++;	continue;}
		else vis[te.v]=1;
		if(dfs(te.v,d+1))	return 1;
		vis[te.v]=0;
		p++;
	}
	return 0;
}
int main(){
	int i,j,k;
	edge te;
	cin>>n>>m>>l;
	for(i=0;i<m;i++){
		cin>>te.u>>te.v;
		v[te.u].push_back(num);
		e[num++]=te;
		te.u^=te.v;	te.v^=te.u;	te.u^=te.v;
		v[te.u].push_back(num);
		e[num++]=te;
	}
	cin>>s>>t;
	bfs(t);	vis[s]=1;
	if(dst[s]>l)	cout<<"NO"<<endl;
	else if(dfs(s,0))	cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}

