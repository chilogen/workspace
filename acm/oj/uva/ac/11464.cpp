#include <bits/stdc++.h>
#define reset(a,b)	memset(a,b,sizeof(a))
using namespace std;
int Inf=999999,ans,n;
int a[20][20],b[20][20];
int check(int s)
{
	int i,j,k;
	reset(b,0);
	for(i=1;i<=n;i++)
		if(s&(1<<i))	b[1][i]=1;
		else if(a[1][i])	return Inf;
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n;j++)
		{
			k=b[i-1][j]+b[i][j-1]+b[i][j+1];
			k%=2;
			if(!k&&a[i+1][j])	return Inf;
			b[i+1][j]=k;
		}
	}
	for(i=1,k=0;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]!=b[i][j])	k++;
	return k;
}
int main()
{
	int t,i,j,k,s;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		ans=Inf;
		cin>>n;
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				cin>>a[j][k];
		for(s=0;s<=0xfffe;s=s+2)
			ans=min(ans,check(s));
		if(ans==Inf)	cout<<"Case "<<i<<": -1"<<endl;
		else cout<<"Case "<<i<<": "<<ans<<endl;
	}
	return 0;
}