#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Maxn 100010
LL n,p[Maxn],deg[Maxn]={0},lev[Maxn],cnt[Maxn]={0},vis[Maxn]={0};
vector<LL>v[Maxn];
int main(){
	LL i,j,k;
	cin>>n;
	for(i=2,p[1]=0;i<=n;i++){
		cin>>p[i];
		v[p[i]].push_back(i);
		deg[p[i]]++;
	}
	v[0].push_back(1);
	for(i=1;i<=n;i++)cnt[i]=deg[i];
	queue<LL>q;g
	q.push(0);
	lev[0]=0;
	while(!q.empty()){
		i=q.front();q.pop();
		vector<LL>::iterator p=v[i].begin();
		while(p!=v[i].end()){
			lev[*p]=lev[i]+1;
			if(deg[*p]%2)vis[lev[*p]]=!vis[lev[*p]];
			q.push(*p);
			p++;
		}
	}
	for(i=1,j=1;i<=n;i++)if(vis[i])j++;
	cout<<j<<endl;
	return 0;
}