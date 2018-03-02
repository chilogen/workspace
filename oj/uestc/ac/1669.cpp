#include <bits/stdc++.h>
#define reset(a,b)	memset(a,b,sizeof(a))
using namespace std;
typedef unsigned long long LL;
LL dp[110];
int main()
{
	string s;
	LL n,l,i,j,k;
	cin>>n;
	for(l=1;l<=n;l++)
	{
		reset(dp,0);
		dp[0]=dp[1]=1;
		cin>>s;	s=" "+s;
		if(s[1]=='0')
		{
			cout<<"Case #"<<l<<": "<<0<<endl;
			continue;
		}
		for(i=2;i<s.length();i++)
		{
			j=s[i-1]-'0';
			k=s[i]-'0';
			if(j*10+k<=26&&j*10+k>=10)
			{
				if(k==0)
					dp[i]=dp[i-2];
				else dp[i]=dp[i-2]+dp[i-1];
			}
			else if(j*10+k>26)
			{
				if(k==0)	break;
				else dp[i]=dp[i-1];
			}
			else if(j*10+k<10)
			{
				if(j==0&&k==0)	break;
				dp[i]=dp[i-1];
			}
		}
		cout<<"Case #"<<l<<": "<<dp[s.length()-1]<<endl;
	}
	return 0;
}