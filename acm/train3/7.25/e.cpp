#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,c,vis[10010]={0};
int main(){
	cin>>n>>c;
	LL i,j;
	if(n==c){
		cout<<"*";
		return 0;
	}
	for(i=0;i<c;i++){
		cin>>j;
		vis[j]=1;
	}
	for(i=1;i<=n;i++)if(!vis[i])cout<<i<<" ";
	return 0;
}