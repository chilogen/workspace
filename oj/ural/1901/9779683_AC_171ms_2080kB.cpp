#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100010],n,s,ans[100010],trip=0;
int main()
{
	LL i,j,k,p,p1,p2;
	cin>>n>>s;
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	a[n]=(LL)1e10;
	sort(a,a+n);
	p=p1=0;	p2=n-1;
	while(p1<p2)
	{
		if(a[p1]+a[p2]>s)
		{
			ans[p++]=a[p1];
			ans[p++]=a[p2];
			a[p1]=-1;	a[p2]=-1;
			p1++;	p2--;
		}
		else p1++;
	}
	k=p;
	for(i=n-1;i>=0;i--)
	{
		if(a[i]!=-1)	ans[p++]=a[i];
	}
	for(i=0;i<n;i++)
	{
		if(ans[i]+ans[i+1]<=s)	i++;
		trip++;
	}
	cout<<trip<<endl;
	for(i=0;i<p;i++)	cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}