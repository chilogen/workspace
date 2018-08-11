#include <bits/stdc++.h>
using namespace std;
int a,fat[1010];
int fin(int x)
{
	if(x==fat[x])	return x;
	else return fat[x]=fin(fat[x]);
}
int main()
{
	int t,n,i,j,k,l,ans;
	cin>>t;
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)	fat[i]=i;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			k=fin(i);
			fat[a]=k;
		}
		for(i=1;i<=n;i++)
		{
			if(fat[i]==i)	ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}