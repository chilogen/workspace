#include<stdio.h>
typedef struct 
{
	int left,right;
	long long add,mul;
	long long sum;
}tree;
tree a[100000*4];
int n;
long long q;
void pushdown(int x)
{
	if(a[x].add!=0 && a[x].mul!=1)
	{
		a[2*x].add=(a[x].add+a[2*x].add*a[x].mul)%q;
		a[2*x].mul=(a[x].mul*a[2*x].mul);
		a[2*x+1].add=(a[x].add+a[2*x+1].add*a[x].mul)%q;
		a[2*x+1].mul=(a[x].mul*a[2*x+1].mul);
		a[2*x].sum=(a[2*x].sum*a[x].mul%q+a[x].add*(a[2*x].right-a[2*x].left+1)%q)%q;
		a[2*x+1].sum=(a[2*x+1].sum*a[x].mul%q+a[x].add*(a[2*x+1].right-a[2*x+1].left+1)%q)%q;
		a[x].add=0;	a[x].mul=1;
	}
}
void build(int start,int end,int x)
{
	a[x].left=start;	a[x].right=end;
	a[x].add=0;	a[x].mul=1;
	if(start==end)
	{
		scanf("%lld",&a[x].sum);
		return ;
	}
	int k=(start+end)/2;
	build(start,k,2*x);	build(k+1,end,2*x+1);
	a[x].sum=(a[2*x].sum+a[2*x+1].sum)%q;
	return ;
}
void update(int start,int end,int x,long long c,int op)
{
	if(a[x].left>=start&&a[x].right<=end)
	{
		if(op==1)
		{
			a[x].mul=a[x].mul*c%q;
			a[x].add=a[x].add*c%q;
			a[x].sum=a[x].sum*c%q;
		}
		else
		{
			a[x].add=(a[x].add+c%q)%q;
			a[x].sum=(a[x].sum+(a[x].right-a[x].left+1)*c%q);
		}
		return ;
	}
	pushdown(x);
	int m=(a[x].left+a[x].right)/2;
	if(m>=start)	update(start,end,2*x,c,op);
	if(m<end)  update(start,end,2*x+1,c,op);
	a[x].sum=(a[2*x].sum+a[2*x+1].sum)%q;
}
int queue(int start,int end,int x)
{
	if(a[x].left>=start&&a[x].right<=end)
		return a[x].sum;
	pushdown(x);
	int m=(a[x].left+a[x].right)/2,ans=0;
	if(m>=start)	ans+=queue(start,end,2*x);
	if(m<end)	ans+=queue(start,end,2*x+1);
	return ans%q;
}
int main()
{
//	freopen("abc","r",stdin);
	int x,y,p,op;
	long long c;
	scanf("%d%lld",&n,&q);
	build(1,n,1);
	scanf("%d",&p);
	while(p--)
	{
		scanf("%d",&op);
		if(op!=3)
		{
			scanf("%d%d%lld",&x,&y,&c);
			update(x,y,1,c,op);
		}
		else
		{
			scanf("%d%d",&x,&y);
			printf("%d\n",queue(x,y,1));
		}
	}
//	fclose(stdin);
	return 0;
}