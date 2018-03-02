#include <bits/stdc++.h>
using namespace std;
#define reset(a,b) memset(a,b,sizeof(a))
typedef long long LL;
int main()
{
	LL n,ans,s;
	LL a[200001],sum[100001];
	LL i,j,k;
	cin>>n;
	sum[0]=0;	s=0;	ans=LL(1e18);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
		s+=a[i];
	}
	for(i=1;i<n;i++)
	{
		ans=min(ans,abs(s-2*sum[i]));
	}
	cout<<ans<<endl;
	return 0;
}