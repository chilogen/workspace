#include <bits/stdc++.h>
using namespace std;
int vis[17]={0},n,a[17];
bool isprime(int x)
{
	int i;
	for(i=2;i<=sqrt(x);i++)
		if(x%i==0)	return false;
	return true;
}
void dfs(int x)
{
	int i;
	if(x==n+1&&isprime(1+a[n]))
	{
		for(i=1;i<n;i++)	cout<<a[i]<<" ";
		cout<<a[i]<<endl;
	}
	for(i=2;i<=n;i++)
	{
		if(!vis[i]&&isprime(i+a[x-1]))
		{
			a[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main()
{
	int i=1;
	a[1]=1;
	while(cin>>n)
	{
		if(i>1)	cout<<endl;
		cout<<"Case "<<i++<<":"<<endl;
		dfs(2);
	}
	return 0;
}