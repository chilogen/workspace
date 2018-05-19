#include <bits/stdc++.h>
#define reset(a,b) memset(a,b,sizeof(a))
int main()
{
	long int n,i,j,k;
	char *s;
	long int *m,*dp;
	scanf("%ld",&n);
	s=new char[n+1];
	m=new long[n+1];
	dp=new long[n+1];
	scanf("%s",s+1);
	reset(m,0);
	reset(dp,0);
	j=0;
	for(i=2;i<=n;i++)
	{
		while(j>0&&s[j+1]!=s[i])	j=m[j];
		if(s[j+1]==s[i])	j++;
		m[i]=j;
	}
	long int sum=0;
	for(i=1;i<=n;i++)
	{
		dp[i]=(dp[m[i]]+1)%10007;
		sum+=dp[i];
		sum%=10007;
	}
	printf("%ld",sum);
	return 0;
}