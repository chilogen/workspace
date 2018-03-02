#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct num
{
	int v,ind;
}a[100010];
LL n;
bool cmp(num a,num b)
{
	if(a.v==b.v)	return a.ind<b.ind;
	return a.v<b.v;
}
int main()
{
	ios::sync_with_stdio(false);
	LL i,j,k,ans=999999;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i].v;
		a[i].ind=i;
	}
	sort(a,a+n,cmp);
	for(i=1;i<n;i++)
	{
		if(a[i].v==a[i-1].v&&a[i].ind-a[i-1].ind<ans)
			ans=a[i].ind-a[i-1].ind;
		else if(a[i].v!=a[i-1].v)	break;
	}
	cout<<ans<<endl;
	return 0;
}