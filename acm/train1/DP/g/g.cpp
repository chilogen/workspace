#include <bits/stdc++.h>
using namespace std;
stack <int> s;
int max(int a,int b)
{
	if(a>b)	return a;
	return b;
}
int main()
{
	//freopen("abc","r",stdin);
	int n,t;
	int a[1001],dp[1001],f[1001];
	int i,j,k,l;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		memset(f,-1,sizeof(f));
		scanf("%d",&n);
		dp[0]=0;	a[0]=0;
		for(i=1;i<=n;i++)	scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
		{
			k=0;	l=0;
			for(j=i-1;j>0;j--)	
				if(a[j]<a[i]&&dp[j]>k)	
					{k=dp[j];	l=j;}
			dp[i]=max(0,k)+1;
			f[i]=l;
		}
		k=0;
		for(i=n;i>=1;i--)	if(dp[i]>k)	{k=dp[i];	l=i;}
		printf("%d ",k);
		k=-1;
		s.push(a[l]);
		k=f[l];
		while(k!=0)
		{
			s.push(a[k]);
			k=f[k];

		}
		while(!s.empty())
		{
			i=s.top();
			s.pop();
			printf("%d ",i);
		}
		printf("\n");
		//for(i=0;i<=n;i++)	printf("%d ",f[i]);
		//	printf("\n");
	}
	//fclose(stdin);
	return 0;
}