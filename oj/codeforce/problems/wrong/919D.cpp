//TLE

#include <bits/stdc++.h>
using namespace std;
struct edge{
	int u,v;
}e[300010];
vector<int>v[300010];
queue<int>q;
int nume=0,n,m,degin[300010]={0},degout[300010]={0},ans=1;
bool vis[300010]={0};
char c[300010];
int num[26];
void dfs(int x){
	int i,j;
	if(degout[x]==0){
		for(i=0;i<26;i++){
			if(num[i]>ans)	ans=num[i];
		}
		return ;
	}
	vector<int>::iterator p=v[x].begin();
	while(p!=v[x].end()){
		edge &te=e[*p];
		if(vis[te.v]){
			cout<<-1<<endl;
			exit(0);
		}
		vis[te.v]=1;
		num[c[te.v]-'a']++;
		dfs(te.v);
		vis[te.v]=0;
		num[c[te.v]-'a']--;
		p++;
	}
}
int main(){
	int i,j,k,l,a,b;
	bool kk=false;
	cin>>n>>m;
	c[300009]=getchar();
	for(i=1;i<=n;i++)
		c[i]=getchar();
	for(i=0;i<m;i++){
		cin>>a>>b;
		if(a==b)	kk=true;
		e[nume].u=a;
		e[nume].v=b;
		degin[b]++;
		degout[a]++;
		v[a].push_back(nume);
		nume++;
	}
	if(kk){
		cout<<-1<<endl;
		return 0;
	}
	for(i=1;i<=n;i++){
		if(degin[i]==0)	q.push(i);
	}
	if(q.empty()){
		cout<<-1<<endl;
		return 0;
	}
	while(!q.empty()){
		k=q.front();	q.pop();
		vis[k]=1;
		num[c[k]-'a']++;
		dfs(k);
		vis[k]=0;
		num[c[k]-'a']--;
	}
	cout<<ans<<endl;
	return 0;
}