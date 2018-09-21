#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=998244353;
LL dp[1010][2010][4]={0},n,k;
int main(){
	LL i,j;
	cin>>n>>k;
	dp[1][1][0]=dp[1][1][3]=1;
	dp[1][2][1]=dp[1][2][2]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=k;j++){
			dp[i][j][0]+=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j-1][3]);
			dp[i][j][0]%=mod;

			dp[i][j][1]+=(dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j-1][3]);
			if(j-2>0)dp[i][j][1]+=+dp[i-1][j-2][2];
			dp[i][j][1]%=mod;

			dp[i][j][2]+=(dp[i-1][j-1][0]+dp[i-1][j][2]+dp[i-1][j-1][3]);
			if(j-2>0)dp[i][j][2]+=dp[i-1][j-2][1];
			dp[i][j][2]%=mod;
			
			dp[i][j][3]+=(dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][3]);
			dp[i][j][3]%=mod;
		}
	}
	cout<<(dp[n][k][0]+dp[n][k][1]+dp[n][k][2]+dp[n][k][3])%mod<<endl;
	return 0;
}