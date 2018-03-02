#include <bits/stdc++.h>
#define reset(a,b)	memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
char s[300010];
LL ch[400010][26],val[400010],dp[300010],tot=0,n,mod=20071027,le;
void insert(char *s)
{
	LL len=strlen(s),i,j,rt=0;
	for(i=0;i<len;i++)
	{
		j=s[i]-'a';
		if(!ch[rt][j])	ch[rt][j]=++tot;
		rt=ch[rt][j];
	}
	val[rt]=1;
}
LL query(LL x)
{
	LL ans=0,i,j,k,rt=0;
	for(i=x;i<le&&(i-x)<100;i++)
	{
		j=s[i]-'a';
		if(!ch[rt][j])	return ans;
		rt=ch[rt][j];
		if(val[rt])	ans=(ans+dp[i+1])%mod;
	}
	return ans;
}
int main()
{
	LL i,j,k=0;
	char temp[110];
	while(scanf("%s",s)!=EOF)
	{
		k++;
		tot=0;	le=strlen(s);
		reset(ch,0);	reset(val,0);	reset(dp,0);	dp[strlen(s)]=1;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",temp);
			insert(temp);
		}
		for(i=strlen(s)-1;i>=0;i--)
			dp[i]=(dp[i]+query(i))%mod;
		printf("Case %lld: %lld\n",k,dp[0]);
	}
	return 0;
}