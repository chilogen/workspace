#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dp[3100][4]={0},s[3100],c[3100],n,ans=1e15;
int main(){
	LL i,j,k;
	cin>>n;
	for(i=0;i<n;i++)cin>>s[i];
	for(i=0;i<n;i++)cin>>c[i];
	dp[0][0]=0;dp[0][1]=c[0];dp[0][2]=1e15;dp[0][3]=1e15;
	for(i=1;i<n;i++){
		dp[i][1]=c[i];
		for(k=2;k<=3;k++)dp[i][k]=1e15;
		for(j=i-1;j>=0;j--){
			if(s[j]>=s[i])continue;
			for(k=1;k<=3;k++)
				dp[i][k]=min(dp[i][k],dp[j][k-1]+c[i]);
		}
	}
	for(i=0;i<n;i++)ans=min(ans,dp[i][3]);
	if(ans==(LL)1e15)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}