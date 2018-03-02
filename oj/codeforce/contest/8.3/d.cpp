#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dp[210][210][4000],five[210],two[210],n,k,a;
int main()
{
	LL i,j,l,ans=0;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		l=0;
		while(a%2==0)
		{
			a=a>>1;
			l++;
		}
		two[i]=l;	l=0;
		while(a%5==0)
		{
			a=a/5;
			l++;
		}
		five[i]=l;
	}
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i+1;j++)
		{
			for(k=3999;k>=0;k--)
			{
				if(k-five[i]<0)	break;
				dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-five[i]]+two[i]);
				dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-five[i]]);
			}
		}
	}
	for(i=0;i<4000;i++)
		ans=max(ans,min(i,dp[n][k][i]));
	cout<<ans<<endl;
	return 0;
}