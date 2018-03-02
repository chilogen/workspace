#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n,m,a[102][102];
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	LL num=0,ans=0;
	LL i,j,k,l;
	char c;
	cin>>n>>m;
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			c=getchar();
			if(c=='\n'){j--;	continue;}
			a[i][j]=c-'0';
			if(a[i][j]!=0)	num++;
		}
	}
	ans=2*num;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i-1][j]<a[i][j])	ans=ans+a[i][j]-a[i-1][j];
			if(a[i+1][j]<a[i][j])	ans=ans+a[i][j]-a[i+1][j];
			if(a[i][j-1]<a[i][j])	ans=ans+a[i][j]-a[i][j-1];
			if(a[i][j+1]<a[i][j])	ans=ans+a[i][j]-a[i][j+1];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}