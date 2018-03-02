#include <bits/stdc++.h>
#define reset(a,b)	memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
LL dp[100010],w[101],sum;
int main()
{
	LL t,n,i,j,k;
	cin>>t;
	for(k=1;k<=t;k++)
	{
		sum=0;	reset(dp,0);
		cin>>n;
		for(i=0;i<n;i++)	
		{
			cin>>w[i];
			sum+=w[i];
		}
		dp[0]=1;
		for(j=0;j<n;j++)	for(i=sum/2;i>=w[j];i--)
				dp[i]|=(dp[i-w[j]]<<1);
		for(j=sum/2;;j--)
		{
			if(dp[j]&((LL)1<<(n/2)))	break;
			if(n%2==1&&dp[j]&((LL)1<<(n/2+1)))	break;
		}
		cout<<"Case "<<k<<": "<<j<<" "<<sum-j<<endl;
	}
	return 0;
}