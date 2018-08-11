#include <bits/stdc++.h>
using namespace std;
long long dp[500000],c[15],w[15],n,t,all,years,d,i,j,k;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>all>>years>>d;
		for(i=0;i<d;i++)	cin>>c[i]>>w[i];
		memset(dp,0,sizeof(dp));
		for(k=0;k<years;k++)
		{
			for(j=0;j<d;j++)	for(i=c[j]/1000;i<=all/1000;i++)
					dp[i]=max(dp[i],dp[i-c[j]/1000]+w[j]);
			all+=dp[all/1000];
		}
		cout<<all<<endl;
	}
	return 0;
}