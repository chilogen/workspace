#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
long long x[2000];
char y[10];
long long dp[2000][10][3];
long long pro(long long a,int i,long long b)
{
	if (y[i]=='+') return a+b;
	else if (y[i]=='-') return a-b;
	else if (y[i]=='*') return a*b;
	else if (y[i]=='/') return a/b;
}
int main()
{
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	int n,m,t,k,v;
	long long p,q;
	scanf("%d\n",&t);
	while (t--)
	{
		scanf("%d%d%d\n",&n,&m,&k);
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		scanf("\n");
		for (int i=1;i<=m;i++)
		{
			scanf("%c",&y[i]);
		}
		dp[0][0][0]=k;
		dp[0][0][1]=k;
		for (int i=1;i<=n;i++)
		{
			if (i<=m) v=i;
			else v=m;
			dp[i][0][0]=dp[i-1][0][0];
			dp[i][0][1]=dp[i-1][0][1];
			for (int j=1;j<=v;j++)
			{
				p=pro(dp[i-1][j-1][0],j,x[i]);
				q=pro(dp[i-1][j-1][1],j,x[i]);
				dp[i][j][0]=max(p,q);
				if (i>j) dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][0]);
				dp[i][j][1]=min(p,q);
				if (i>j) dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]);
			}
		}
		printf("%lld\n",dp[n][m][0]);
	}
	return 0;
}