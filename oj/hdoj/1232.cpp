#include <bits/stdc++.h>
using namespace std;
set <int>s;
int fat[100001];
int fin(int x)
{
	if(fat[x]==x)	return x;
	return fat[x]=fin(fat[x]);
}
int main()
{
	freopen("abc","r",stdin);
	int n,m,i,j,k,l;
	scanf("%d",&n);
	while(n!=0)
	{
		for(i=1;i<=n;i++)
			fat[i]=i;
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&j,&k);
			j=fin(j);
			k=fin(k);
			fat[j]=k;
		}
		for(i=1;i<=n;i++)
			fat[i]=fin(fat[i]);
		for(i=1;i<=n;i++)
			s.insert(fat[i]);
		j=s.size()-1;
		printf("%d\n",j);
		s.clear();
		scanf("%d",&n);
	}
	fclose(stdin);
	return 0;
}