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
		b[x]=(b[x]+b[a[x]]+1)%2;
		return a[x]=i;
	}
}
int build(int i,int j,int k)
{
	int x=find(j),y=find(k);
	if(x==y)
	{
		if((b[j]+b[k])%2==0)
		{
			if(i==1) return 1;
			else return 0;
		}
		else if(i==0) return 1;
		else return 0;
	}
	a[x]=y;
	b[x]=(b[j]+b[k]+i)%2;
	return 1;
}

int main()
{
//	freopen("abc","r",stdin);
	int n,q,i,j,k,l;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		a[i]=i;
		b[i]=1;
	}
	l=1;
	while(q--)
	{
		scanf("%d%d%d",&i,&j,&k);
		if(l)
		{
			l=build(i,j,k);
			if(l==0) printf("NO");
		}
	}
	if(l==1) printf("YES");
//	fclose(stdin);
	return 0;
}







/*#include<stdio.h>
int a[100001];
int b[100001];
int find(int x)
{
	int i;
	if(x==a[x]) return x;
	else
	{
		i=find(a[x]);
		b[x]=(b[x]+b[a[x]])%2;
		return a[x]=i;
	}
}
int build(int i,int j,int k)
{
	int x=find(j),y=find(k);
	if(x==y)
	{
			if(b[k]==0&&b[j]==1&&i==1) return 0;
			if(b[k]==1&&b[j]==0&&i==1) return 0;
			if(b[k]==0&&b[j]==0&&i==1) return 1;
			if(b[k]==1&&b[j]==1&&i==1) return 1;

			if(b[k]==0&&b[j]==1&&i==0) return 1;
			if(b[k]==1&&b[j]==0&&i==0) return 1;
			if(b[k]==0&&b[j]==0&&i==0) return 0;
			if(b[k]==1&&b[j]==1&&i==0) return 0;
	}
	a[x]=y;
	b[x]=i;
	return 1;
}

int main()
{
	int n,q,i,j,k,l;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		a[i]=i;
		b[i]=1;
	}
	l=1;
	while(q--)
	{
		scanf("%d%d%d",&i,&j,&k);
		if(l)
		{
			l=build(i,j,k);
			if(l==0) printf("NO");
		}
	}
	if(l==1) printf("YES");
	return 0;
}*/