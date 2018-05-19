#include <bits/stdc++.h>
int w[20001],v[20001],mark[20001],cap[10001];
int n,k;
int max(int a,int b)
{
	if(a>b)	return a;
	return b;
}
void zopack(int i,int w,int v)
{
	int j;
	for(j=k;j>=0;j--)
	{
		if(j-w>=0)	cap[j]=max(cap[j],cap[j-w]+v);
		else break;
	}
}
void com(int i,int w,int v)
{
	int j;
	for(j=0;j<=k;j++)
	{
		if(j-w>=0)	cap[j]=max(cap[j],cap[j-w]+v);
		else continue;
	}
}
int main()
{
	int i,j,l;
	memset(cap,0,sizeof(cap));
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d%d%d",&mark[i],&v[i],&w[i]);
	for(i=1;i<=n;i++)
	{
		if(mark[i]==1)	com(i,w[i],v[i]);
		else if(mark[i]==2)	zopack(i,w[i],v[i]);
	}
	printf("%d\n",cap[k]);
	return 0;
}