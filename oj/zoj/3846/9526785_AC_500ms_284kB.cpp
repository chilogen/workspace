#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n,a[100000],i,j,k,t=0;
	while(scanf("%lld",&n)!=EOF)
	{
		t++;
		for(i=0;i<n;i++)	scanf("%lld",&a[i]);
		for(i=1;i<n;i++)
		{
			a[0]=a[i]=__gcd(a[0],a[i]);
		}
		if(a[0]==1)
		{
			printf("Case %lld: %lld\n",t,2*n-2);
			for(i=1;i<n;i++)
				printf("1 %lld\n",i+1);
			for(i=1;i<n;i++)
				printf("1 %lld\n",i+1);
			printf("\n");
		}
		else printf("Case %lld: -1\n\n",t);
	}
	return 0;
}