#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL i,j,k,n,p,ans=0;
	LL a[50],way[5001]={0};
	bool b[5001];
	cin>>n>>p;
	for(i=0;i<n;i++)	cin>>a[i];
	sort(a,a+n);
	way[0]=1;
	for(j=0;j<n;j++)
	{
		for(i=5000;i>=0;i--)
		{
			if(i-a[j]<0)	break;
			way[i]+=way[i-a[j]];
		}
	}
	j=p%2;
	for(i=j;i<=5000;i=i+2)
		b[i]=true;
	for(i=0;i<=5000;i++)
	{
		if(b[i])
		{
			ans=ans+way[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}