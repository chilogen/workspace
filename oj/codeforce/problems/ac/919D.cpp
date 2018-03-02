#include <bits/stdc++.h>
using namespace std;
int deg[300010]={0},n,m,ans=1;
struct edge{
	int u,v;
}e[300010];
vector<int>v[300010];
queue<int>q;
char c[300010];
int nume=0,num[300010][26]={0};
bool have_cir(){
	queue<int>qq=q;
	int ddeg[300010];
	memcpy(ddeg,deg,sizeof(deg));
	int i,j;
	while(!qq.empty()){
		i=qq.front();qq.pop();
		vector<int>::iterator p=v[i].begin();
		while(p!=v[i].end()){
			edge &te=e[*p];
			ddeg[te.v]--;
			if(ddeg[te.v]==0)	qq.push(te.v);
			p++;
		}
	}
	for(i=1;i<=n;i++){if(ddeg[i]!=0)	return true;}
	return false;
}
int main(){
	int a,b,i,j,k;
	bool kk=false;
	cin>>n>>m;
	c[0]=getchar();
	for(i=1;i<=n;i++)c[i]=getchar();
	for(i=0;i<m;i++){
		cin>>a>>b;
		if(a==b)	kk=true;
		deg[a]++;
		e[nume].u=b;
		e[nume].v=a;
		v[b].push_back(nume);
		nume++;
	}
	for(i=1;i<=n;i++){
		if(deg[i]==0)	q.push(i);
	}
	if(kk||have_cir()){
		cout<<-1<<endl;
		return 0;
	}
	while(!q.empty()){
		k=q.front();q.pop();
		num[k][c[k]-'a']++;
		vector<int>::iterator p=v[k].begin();
		while(p!=v[k].end()){
			edge &te=e[*p];
			for(i=0;i<26;i++){
				if(num[k][i]>num[te.v][i])	num[te.v][i]=num[k][i];
			}
			deg[te.v]--;
			if(deg[te.v]==0)	q.push(te.v);
			p++;
		}
	}
	for(i=1;i<=n;i++){
		for(j=0;j<26;j++)
		if(num[i][j]>ans)	ans=num[i][j];
	}
	cout<<ans<<endl;
	return 0;
}