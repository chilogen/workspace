#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dp[21],c[21][21];
int main()
{
	int i,j,k,l,p,n;
	memset(dp,0,sizeof(dp));
	dp[1]=1;	dp[2]=2;	dp[3]=4;
	c[0][0]=1;
	for(i=1;i<=20;i++)
	{
		c[i][0]=1;
		for(j=1;j<=i;j++)
		c[i][j]=(c[i-1][j-1]+c[i-1][j]);
	}
	for(i=4;i<=20;i++)
	{
		dp[i]+=dp[i-1];
		for(j=1;j<i;j++)
		{
			if(j==1|i-j-1==1)	dp[i]=dp[i]+dp[j]*dp[i-j-1]*c[i-1][j]/2;
			else dp[i]=dp[i]+dp[j]*dp[i-j-1]*c[i-1][j]/4;
		}
	}
	cin>>p;
	while(p--)
	{
		cin>>k>>n;
		cout<<k<<" "<<dp[n]<<endl;
	}
	return 0;
}