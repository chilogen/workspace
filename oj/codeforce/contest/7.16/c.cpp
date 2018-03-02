#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n,k,a[1000],i,j;
	cin>>n>>k;
	for(i=0;i<n;i++)	cin>>a[i];
	sort(a,a+n);
	for(i=0,j=0;i<n;i++)
	{
		while(a[i]>2*k)
		{
			j++;k*=2;
		}
		k=max(k,a[i]);
	}
	cout<<j<<endl;
	return 0;
}