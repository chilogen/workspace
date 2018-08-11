#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[200010];
int main()
{
	cin>>n;
	LL i,j;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]-=(n-i);
	}
	sort(a,a+n);
	for(i=1;i<n;i++)
		if(a[i]==a[i-1])
		{
			cout<<":("<<endl;
			return 0;
		}
	for(i=0;i<n;i++)	printf("%lld ",a[i]+(n-i));
	return 0;
}