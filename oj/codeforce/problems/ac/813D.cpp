#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,k,p,i,j,l;
	cin>>n>>k>>p;
	long long a[1010],b[2020];
	long long c=-1,ans=1000000000000000000;
	for(i=0;i<n;i++)	cin>>a[i];
	for(i=0;i<k;i++)	cin>>b[i];
	sort(a,a+n);	sort(b,b+k);
	for(i=0;i<k-n+1;i++)
	{
		c=-1;
		for(j=0;j<n;j++)
		{
			c=max(c,abs(p-b[j+i])+abs(b[j+i]-a[j]));
		}
		ans=min(ans,c);
	}
	cout<<ans<<endl;
	return 0;
}