#include <bits/stdc++.h>
using namespace std;
#define reset(a,b)	memset(a,b,sizeof(a))
int vis[1010],dst[1010]={0},dt[1010],ma[1010][1010],vi[1010];
int n,m,s,t,ans=0;
int main(){

	cin>>n>>m>>s>>t;
	int i,j,k;
	reset(ma,0);
	for(i=0;i<m;i++){
		cin>>j>>k;
		ma[j][k]=ma[k][j]=1;
	}
	for(i=0;i<=n;i++)dt[i]=dst[i]=50000;
	reset(vis,0);
	queue<int>bfs;	vis[s]=1;	bfs.push(s);	dst[s]=0;
	while(!bfs.empty()){
		i=bfs.front();bfs.pop();
		for(j=1;j<=n;j++){
			if(!ma[i][j]||vis[j])continue;
			vis[j]=1;
			dst[j]=dst[i]+1;
			if(j!=t)bfs.push(j);
		}
	}
	reset(vis,0);
	vis[t]=1;	bfs.push(t);	dt[t]=0;
	while(!bfs.empty()){
		i=bfs.front();bfs.pop();
		for(j=1;j<=n;j++){
			if(!ma[i][j]||vis[j])continue;
			vis[j]=1;
			dt[j]=dt[i]+1;
			if(j!=t)bfs.push(j);
		}
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(ma[i][j])continue;
			if(dst[i]+dt[j]+1>=dst[t]&&dst[j]+dt[i]+1>=dst[t])ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}