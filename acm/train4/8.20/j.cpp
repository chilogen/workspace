#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;
struct node{
	int l,r,ma;
}tree[600000];
int x[110000],y[110000],z[110000],a,b,c;
void build(int k,int l,int r)
{
	tree[k].l=l;
	tree[k].r=r;
	if (l==r)
	{
		tree[k].ma=x[l];
	}
	else{
		int m=(l+r)/2;
		build(k*2,l,m);
		build(k*2+1,m+1,r);
		tree[k].ma=max(tree[k*2].ma,tree[k*2+1].ma);
	}
	return;
}
void find(int k,int l,int v)
{
	if (tree[k].ma<=v) return;
	else
	if (tree[k].l==tree[k].r)
	{
		if (tree[k].ma>v && tree[k].l<c)
		   c=tree[k].l; 
	}
	else
	{
		if (tree[k*2].r>l && tree[k*2].ma>v)
		{
			find(k*2,l,v);
		}
		if (c==10000000)
		if (tree[k*2+1].r>l && tree[k*2+1].ma>v)
		{
            find(k*2+1,l,v);
		}
	}
	return;
}
int main()
{
	int n,m,t,p,q,ans;
	scanf("%d\n",&t);
	while (t>0)
	{
		t=t-1;
		scanf("%d%d\n",&n,&m);
        for (int i=1;i<=n;i++)
		{
			scanf("%d",&x[i]);
		}
		build(1,1,n);
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		y[1]=1;
		z[1]=0;
		p=1;
		q=1;
		for (int i=2;i<=n;i++)
		{
			z[i]=p;
            if (x[i]>x[p])
			{
				y[i]=q+1;
				q=q+1;
				p=i;
			}			
		}
		z[n+1]=p;
		for (int i=1;i<=m;i++)
		{
			ans=0;
            scanf("%d%d\n",&a,&b);
            ans=y[z[a]];
			if (b>x[z[a]]) ans+=1;
			c=10000000;
			find(1,a,b);
//			printf("%d %d c=%d\n",a,b,c);
			if (c!=10000000)
			{
                ans+=y[z[n+1]]-y[z[c]];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}