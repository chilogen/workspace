#include <bits/stdc++.h>
int w[101],p[101],c[101],n,t,cap[50001];
int max(int a,int b)
{
	if(a>b)	return a;
	return b;
}
void zo_pack(int w,int p)
{
	int i;
	for(i=t;i>=0;i--)
	{
		if(i-w<0)	return;
		else cap[i]=max(cap[i],cap[i-w]+p);
	}
}
void com_pack(int w,int p)
{
	int i;
	for(i=0;i<=t;i++)
	{
		if(i-w<0)	continue;
		else cap[i]=max(cap[i],cap[i-w]+p);
	}
}
int main()
{
	freopen("abc","r",stdin);
	scanf("%d%d",&n,&t);
	memset(cap,0,sizeof(cap));
	int i,j,k,l;
	for(i=1;i<=n;i++)	scanf("%d%d%d",&w[i],&p[i],&c[i]);
	for(i=1;i<=n;i++)
	{
		if(w[i]*c[i]>t)	com_pack(w[i],p[i]);
		else
		{
			j=1;
			while(j<c[i])
			{
				zo_pack(w[i]*j,p[i]*j);
				c[i]-=j;
				j*=2;
			}
			zo_pack(w[i]*c[i],p[i]*c[i]);
		}
	}
	printf("%d\n",cap[t]);
	fclose(stdin);
	return 0;
}