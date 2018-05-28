#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,dp[80],Case=0;
int main(){
	dp[0]=dp[1]=dp[2]=dp[3]=1;
	LL i;
	for(i=4;i<=76;i++)	
		dp[i]=dp[i-2]+dp[i-3];
	cin>>n;
	while(n!=0){
		Case++;
		cout<<"Case #"<<Case<<": ";
		if(n<=2)cout<<0<<endl;
		else if(n==3)cout<<1<<endl;
		else cout<<dp[n]+dp[n-1]<<endl;
		cin>>n;
	}
	return 0;
}