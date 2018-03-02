#include<stdio.h>
int a[100001];
int b[100001];
int find(int x)
{
	int i;
	if(x==a[x]) return x;
	else
	{
		i=find(a[x]);
		b[x]=(b[x]+b[a[x]])%3;
		return a[x]=i;
	}
}
int build(int i,int j,int k)
{
	int x=find(j),y=find(k);
	if(x==y)
	{
		if((b[j]-b[k]+3)%3==i-1)
			return 0;
		return 1;
	}
	a[x]=y;
	b[x]=(-b[j]+i-1+b[k]+3)%3;
	return 0;
}

int main()
{
	int n,q,i,j,k,l;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		a[i]=i;
		b[i]=0;
	}
	l=0;
	while(q--)
	{
		l++;
		scanf("%d%d%d",&i,&j,&k);
		if(i==2&&j==k) printf("%d ",l);
		else if(j>n||k>n) printf("%d ",l);
		else if(build(i,j,k)) printf("%d ",l);
	}
	return 0;
}