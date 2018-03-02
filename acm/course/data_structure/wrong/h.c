#include<stdio.h>
#define MAXN 7000
struct tree
{
	int x0;
	int d;
	int max;
}a[MAXN*4];
int b{MAXN};
void build(x0,d,x)
{
	
}
int main()
{
	int n,i,j,k,op;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	build(1,n,1);
	scanf("%d",&i);
	while(i--)
	{
		scanf("%d%d%d",*op,&j,&k);
		if(op==0) change(j,k);
		else printf("%d\n",find(j,k));
	}
	return 0;
}
