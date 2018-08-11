#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n,k,i,a[100010];
	cin>>n>>k;
	for(i=0;i<n;i++)	cin>>a[i];
	sort(a,a+n);
	if(a[n-1]==k)
	{
		puts("POSSIBLE");
		return 0;
	}
	if(a[n-1]<k)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	for(i=1;i<n;i++)
	{
		if(__gcd(a[0],a[i])==1)
		{
			puts("POSSIBLE");
			return 0;
		}
		if(__gcd(a[0],k)==__gcd(a[i],a[0])&&__gcd(a[0],k)!=1)
		{
			puts("POSSIBLE");
			return 0;
		}
	}
	puts("IMPOSSIBLE");
	return 0;
}