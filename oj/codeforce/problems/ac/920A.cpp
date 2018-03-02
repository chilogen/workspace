#include <bits/stdc++.h>
using namespace std;
int vis[210],t,n,k;
int main(){
	int i,j;
	cin>>t;
	while(t--){
		queue<int>q;
		memset(vis,0,sizeof(vis));
		cin>>n>>k;
		for(i=0;i<k;i++){
			cin>>j;
			vis[j]=1;
			q.push(j);
		}
		while(!q.empty()){
			i=q.front();
			q.pop();
			if(i-1>0&&vis[i-1]==0){
				q.push(i-1);
				vis[i-1]=vis[i]+1;
			}
			if(i+1<=n&&vis[i+1]==0){
				q.push(i+1);
				vis[i+1]=vis[i]+1;
			}
		}
		for(i=1,j=0;i<=n;i++){
			if(vis[i]>j)	j=vis[i];
		}
		cout<<j<<endl;
	}
	return 0;
}