#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
LL dp[2][2050];
inline LL checkbit(LL x,LL y){return x&(1ll<<y);}
int main()
{
	LL i,j,k,cur,nexstat,full_stat;
	while(cin>>n>>m){
		i=n+m;
		n=i-min(n,m);
		m=i-n;
		cur=0;full_stat=(1<<m)-1;
		memset(dp[cur],0,sizeof(dp[cur]));
		dp[cur][full_stat]=1;
		for(i=0;i<n;i++)for(j=0;j<m;j++){
			memset(dp[cur^1],0,sizeof(dp[cur^1]));
			for(k=0;k<=full_stat;k++){
				if(checkbit(k,m-1)){
					if(!checkbit(k,0)&&j!=0){
						nexstat=k<<1;
						nexstat^=3;
						nexstat&=full_stat;
						dp[cur^1][nexstat]+=dp[cur][k];
					}
					nexstat=k<<1;
					nexstat&=full_stat;
					dp[cur^1][nexstat]+=dp[cur][k];
				}
				else if(i!=0){
					nexstat=k<<1;
					nexstat^=1;
					nexstat&=full_stat;
					dp[cur^1][nexstat]+=dp[cur][k];
				}
			}
			cur^=1;
		}
		cout<<dp[cur][full_stat]<<endl;
	}
	return 0;
}