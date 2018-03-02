#include <bits/stdc++.h>
using namespace std;
set <int>s;
int a[10001];
int main()
{
	freopen("abc","r",stdin);
	int n,m,i,j,k,l,r,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while(m--)
	{
		scanf("%d%d%d",&l,&r,&x);
		j=x-l;	k=0;
		for(i=l;i<=r;i++)
		{
			if(a[i]<a[x])	k++;
		}
		if(k==j)	printf("Yes\n");
		else printf("No\n");
	}
	fclose(stdin);
	return 0;
}