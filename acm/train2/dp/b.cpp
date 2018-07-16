#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[210],dp[210][210]={0};
int main(){
	LL i,j,k,r;
	for(i=0;i<209;i++){
		for(j=0;j<210;j++)dp[i][j]=1e18;
		dp[i][i]=dp[i][i+1]=0;
	}
	cin>>n;
	n+=2;
	for(i=0;i<n;i++)cin>>a[i];
	for(k=2;k<n;k++){
		for(i=0;i+k<n;i++){
			for(j=i+1;j<i+k;j++){
				r=i+k;
				dp[i][r]=min(dp[i][r],dp[i][j]+dp[j][r]+a[i]*a[r]*a[j]);
			}
		}
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
}