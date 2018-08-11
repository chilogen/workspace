#include <bits/stdc++.h>
using namespace std;
double dp[2][4000]={0};
int main()
{
	double ab[2],cd[2],e,f;
	int i,j,k;
	cin>>ab[0]>>ab[1]>>cd[0]>>cd[1]>>e>>f;
	double Max=e/100.0;
	memset(dp[1],-1,sizeof(dp[1]));
	dp[1][0]=0;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			for(k=0;k<=f;k++)
			{
				int x=k-100*ab[i]-cd[j];
				if(x<0)	x=k-cd[j];
				if(x<0)	continue;
				if(dp[1][x]==-1)	continue;
				double s=dp[1][x]+cd[j];
				s=s/(double)(k-s);
				if(s>Max||s<=dp[0][k])
				{
					dp[0][k]=dp[0][x];
					dp[1][k]=dp[1][x];
				}
				else if(s>dp[0][k])
				{
					dp[0][k]=s;
					dp[1][k]=dp[1][x]+cd[j];
				}
			}
		}
	}
	Max=0;	j=0;
	for(i=0;i<=f;i++)
	{
		if(dp[0][i]>Max)	j=i;
	}
	cout<<j<<" "<<dp[1][j]<<endl;
	return 0;
}