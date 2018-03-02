#include<stdio.h>
#include<string.h>
#define MAXN 100
int a[MAXN+1];
void update(int pos,int v,int n)
{
	while(pos<=n)
	{
		a[pos]+=v;
		pos+=pos&-pos;	
	}
}
int rea(int pos)
{
	int ans=0;
	while(pos)
	{
		ans+=a[pos];
		pos-=pos&-pos;	
	}	
	return ans;
}
int main()
{
	int n,i,j,k,l;
	scanf("%d",&n);
	memset(a,0,sizeof(int)*n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		update(i,j,n);
	}
	printf("%d\n",rea(5)-rea(2));
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);	
	}
	return 0;
}