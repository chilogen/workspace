#include<stdio.h>
typedef struct 
{
	long long int left,right;
	long long int add,mul;//两个lazy标签
	long long int sum;//该段 mod 后的和
}tree;
tree a[100000*4];
int n;
long long int q;
void pushdown(int x)//向下更新lazy标签
{
	if(a[x].left!=a[x].right)//如果相等，则已到叶子节点，不需要再下推
	{
		a[2*x].add=(a[x].add+a[2*x].add*a[x].mul)%q;
		a[2*x].mul=(a[x].mul*a[2*x].mul)%q;
		a[2*x+1].add=(a[x].add+a[2*x+1].add*a[x].mul)%q;
		a[2*x+1].mul=(a[x].mul*a[2*x+1].mul)%q;
		a[2*x].sum=(a[2*x].sum*a[x].mul+a[x].add*(a[2*x].right-a[2*x].left+1))%q;
		a[2*x+1].sum=(a[2*x+1].sum*a[x].mul+a[x].add*(a[2*x+1].right-a[2*x+1].left+1))%q;
		a[x].add=0;	a[x].mul=1;
	}
}
void build(long long int start,long long int end,int x)
{
	a[x].left=start;	a[x].right=end;
	a[x].add=0;	a[x].mul=1;
	if(start==end)
	{
		scanf("%lld",&a[x].sum);
		return ;
	}
	long long int k=(start+end)/2;
	build(start,k,2*x);	build(k+1,end,2*x+1);
	a[x].sum=(a[2*x].sum+a[2*x+1].sum)%q;
	return ;
}
void update(long long int start,long long int end,int x,long long int c,int op)
{
	if(a[x].left>=start&&a[x].right<=end)//lazy操作
	{
		if(op==1)//乘法
		{
			a[x].mul=a[x].mul*c%q;
			a[x].add=a[x].add*c%q;
			a[x].sum=a[x].sum*c%q;
		}
		else//加法
		{
			a[x].add=(a[x].add+c%q)%q;
			a[x].sum=(a[x].sum+(a[x].right-a[x].left+1)*c)%q;//这就是导致溢出的代码
		}
		return ;
	}
	pushdown(x);
	long long int m=(a[x].left+a[x].right)/2;
	if(m>=start)	update(start,end,2*x,c,op);
	if(m<end)  update(start,end,2*x+1,c,op);
	a[x].sum=(a[2*x].sum+a[2*x+1].sum)%q;//pushup
}
long long int queue(long long int start,long long int end,int x)
{
	if(a[x].left>=start&&a[x].right<=end)
		return a[x].sum;
	pushdown(x);//因为要往下查询，所以要把lazy标签向下更新
	long long int m=(a[x].left+a[x].right)/2;
	long long int ans=0;
	if(m>=start)	ans+=queue(start,end,2*x);
	if(m<end)	ans+=queue(start,end,2*x+1);
	return ans%q;
}
int main()
{
	int p,op;
	long long int c,x,y;
	scanf("%d%lld",&n,&q);
	build(1,n,1);
	scanf("%d",&p);
	while(p--)
	{
		scanf("%d",&op);
		if(op!=3)
		{
			scanf("%lld%lld%lld",&x,&y,&c);
			update(x,y,1,c,op);
		}
		else
		{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",queue(x,y,1));
		}
	}
}
