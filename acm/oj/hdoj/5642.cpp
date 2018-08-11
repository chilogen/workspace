#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const long long mod=1000000007;
int main()
{
	LL t,n,i,j,k,ans;
	LL dp[6][2010];
	memset(dp,0,sizeof(dp));
	dp[1][3]=26;
	dp[2][3]=650;
	dp[3][3]=650;
	dp[4][3]=650;
	dp[5][3]=15600;
	for(i=4;i<=2000;i++)
	{
		dp[1][i]=dp[4][i-1];
		dp[2][i]=(25*dp[1][i-1]%mod+25*dp[4][i-1]%mod)%mod;
		dp[3][i]=(dp[2][i-1]+dp[5][i-1]+dp[3][i-1])%mod;
		dp[4][i]=(dp[2][i-1]+dp[3][i-1]+dp[5][i-1])%mod;
		dp[5][i]=(24*dp[2][i-1]%mod+24*dp[3][i-1]%mod+24*dp[5][i-1]%mod)%mod;
	}
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		if(n==0)
		{
			cout<<0<<endl;
			continue;
		}
		if(n==1)
		{
			cout<<26<<endl;
			continue;
		}
		if(n==2)
		{
			cout<<26*26<<endl;
			continue;
		}
		ans=(ans+dp[1][n])%mod;
		ans=(ans+dp[2][n])%mod;
		ans=(ans+dp[3][n])%mod;
		ans=(ans+dp[4][n])%mod;
		ans=(ans+dp[5][n])%mod;
		cout<<ans<<endl;
	}
	return 0;
}