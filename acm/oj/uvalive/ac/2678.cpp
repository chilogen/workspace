#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100010];
int main()
{
	LL n,s,i,j,k,p1,p2,sum,ans;
	while(scanf("%lld%lld",&n,&s)!=EOF)
	{
		for(i=0;i<n;i++)	scanf("%lld",&a[i]);
		p1=p2=sum=0;	ans=200010;
		while(p2<n)
		{
			if(sum<s)
				sum+=a[p2++];
			else
			{
				ans=min(ans,p2-p1);
				sum-=a[p1++];
			}
		}
		while(sum>=s)
		{
			ans=min(ans,p2-p1);
			sum-=a[p1++];
		}
		if(ans==200010)	cout<<0<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}