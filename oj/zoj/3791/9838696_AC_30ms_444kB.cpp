#include <bits/stdc++.h>
#define reset(a,b)	memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
const LL mod=1000000009;
LL c[101][101],dp[101][101];
char s1[110],s2[110];
int main()
{
	LL i,j,n,k,l,m,diff;
	c[0][0]=1;
	for(i=1;i<=100;i++)
	{
		c[i][0]=1;
		for(j=1;j<=i;j++)
		c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	while(scanf("%lld%lld%lld",&n,&k,&m)!=EOF)
	{
		diff=0;	reset(dp,0);
		scanf("%s%s",s1,s2);
		for(i=0;i<n;i++)	if(s1[i]!=s2[i])	diff++;
		dp[0][diff]=1;
		for (i = 0; i < k; i++) {
            for (j = 0; j <= n; j++) {
                for (l = 0; l <= m; l++) {
                    if((j + 2 * l - m) < 0) continue;
                    if((j + 2 * l - m) > n) break;
                    dp[i + 1][j + 2 * l - m] = (dp[i + 1][j + 2 * l - m] % mod + c[j][m - l] * c[n - j][l] % mod * dp[i][j] % mod) % mod;
                 }
            }
        }
        printf("%lld\n", dp[k][0]);
	}
	return 0;
}