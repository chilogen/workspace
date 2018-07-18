#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,vis[10000]={0},a[10000];
vector<int>e[10000];
void connect(int x,int y){
	e[x].push_back(y);
	e[y].push_back(x);
}
int main(){
	int i,j,k;
	n=0;
	while(scanf("%d",&j)!=EOF)a[++n]=j;
	vis[n+1]=1;k=n;vis[0]=1;
	for(i=n;i>=1;i--){
		if(!vis[a[i-1]]){
			connect(a[i-1],a[i]);
			vis[a[i-1]]=1;
		}
		else{
			while(vis[k])k--;
			connect(k,a[i]);
			vis[k]=1;
			k--;
		}
	}
	for(i=1;i<=n+1;i++){
		cout<<i<<": ";
		sort(e[i].begin(),e[i].end());
		for(j=0;j<(int)e[i].size();j++)cout<<e[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}