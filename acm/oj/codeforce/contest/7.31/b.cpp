#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[100010];
LL a[100010];
LL k;
int main()
{
	char c;
	LL i,j,l,len,sum=0,ans=0;
	scanf("%lld%s",&k,s);
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		a[i]=s[i]-'0';
		sum+=a[i];
	}
	sort(a,a+len);
	i=0;
	while(sum<k)
	{
		j=9-a[i];
		i++;
		sum+=j;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}