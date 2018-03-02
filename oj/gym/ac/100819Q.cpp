#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n,i,j,k;
	LL a[100010];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	k=(LL)1e17;
	for(i=0;i<n/2;i++)
	{
		j=a[i]+a[n-i-1];
		k=min(k,j);
	}
	cout<<k<<endl;
	return 0;
}