#include <bits/stdc++.h>
using namespace std;
int n,m,v,w,dp[1000010]={0};
int main(){
	int i,j;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>v>>w;
		for(j=m;j>=w;j--)dp[j]=max(dp[j],dp[j-v]+w);
	}
	cout<<dp[m]<<endl;
	return 0;
}