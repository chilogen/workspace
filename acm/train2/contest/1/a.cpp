#include <bits/stdc++.h>
using namespace std;
int fron[2000],nex[2000],vis[2000];
int n,m;
int main(){
	int i,j,k,cnt;
	cin>>n>>m;
	while(n!=0&&m!=0){
		cnt=n-1;;
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++){
			if(i==1){
				fron[i]=n;
				nex[i]=i+1;
			}
			else if(i==n){
				nex[i]=1;
				fron[i]=i-1;
			}
			else{
				fron[i]=i-1;
				nex[i]=i+1;
			}
		}
		j=0;nex[0]=1;
		while(cnt--){
			k=m;
			while(k--)	
				j=nex[j];
			vis[j]=1;
			nex[fron[j]]=nex[j];
			fron[nex[j]]=fron[j];
		}
		for(i=1;i<=n;i++)if(vis[i]==0){cout<<i<<endl;break;}
		cin>>n>>m;
	}
	return 0;
}