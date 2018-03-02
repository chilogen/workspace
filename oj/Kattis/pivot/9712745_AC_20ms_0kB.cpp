#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL l[100010],r[100010],a[100010];
int main()
{
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	LL n,i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)	scanf("%lld",&a[i]);
	l[0]=LL(-1e15);	l[1]=a[1];	r[n]=a[n];	r[n+1]=LL(1e15);
	for(i=1;i<=n;i++)
	{
		if(a[i]>l[i-1])	l[i]=a[i];
		else l[i]=l[i-1];
	}
	for(j=n;j>=1;j--)
	{
		if(a[j]<r[j+1])	r[j]=a[j];
		else r[j]=r[j+1];
	}
	LL ans=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]>=l[i-1]&&a[i]<r[i+1])	ans++;
	}
	cout<<ans<<endl;
	return 0;
}