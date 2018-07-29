#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dp[1010],t,n,m;
LL v[1010],w[1010];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	LL i,j,k;
	while(t--){
		cin>>n>>m;
		if(n+m==0)break;
		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		for(i=0;i<n;i++)cin>>w[i];
		for(i=0;i<n;i++)cin>>v[i];
		for(i=0;i<n;i++){
			for(j=m;j>=0;j--){
				k=j-v[i];
				if(k<0)break;
				if(dp[k]==-1)continue;
				dp[j]=max(dp[j],dp[k]+w[i]);
			}
		}
		for(i=m,j=-1,k=0;i>=0;i--){
			if(dp[i]>k){
				k=dp[i];
				j=i;;
			}
		}
		if(j==-1)cout<<"0 0\n";
		else cout<<dp[j]<<" "<<j<<endl;
	}
	return 0;
}