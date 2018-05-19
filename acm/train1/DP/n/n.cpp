#include <bits/stdc++.h>
int main()
{
  long long int i,j,k,n,m,b,mod,bug[501],dp[501][501];
  scanf("%lld%lld%lld%lld",&n,&m,&b,&mod);
  for(i=1;i<=n;i++) scanf("%lld",&bug[i]);
  memset(dp,0,sizeof(dp));  dp[0][0]=1;
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      for(k=bug[i];k<=b;k++)
        dp[j][k]=(dp[j][k]+dp[j-1][k-bug[i]])%mod;
    }
  }
  for(i=0,j=0;i<=b;i++)
    j=(j+dp[m][i])%mod;
  printf("%lld\n",j);
  return 0;
}