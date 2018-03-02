#include<stdio.h>
#define MAXN 100
struct tree
{
	int left;
	int right;
	int max;
	int sum;
}a[MAXN*4];
int b[MAXN];
void build(int start ,int end,int x)//x 代表父节点，初次代1，以1为根节点
{
	a[x].left=start;
	a[x].right=end;
	if(start==end)
	{
		a[x].max=b[start];
		a[x].sum=b[start];
		return ;
	}
	int m=(start+end)/2;
	build(start,m,2*x); build (m+1,end,2*x+1);
	a[x].sum=a[2*x].sum+a[2*x+1].sum;
	if(a[2*x].max>a[2*x+1].max) a[x].max=a[2*x].max;
	else a[x].max=a[2*x+1].max;

}
void change(int pos,int val,int x)//x含义同上
{
	if(a[x].left==a[x].right)
	{
		a[x].sum=val;
		a[x].max=val;
		return ;
	}
	int m=(a[x].left+a[x].right)/2;
	if(pos<m) change(pos,val,2*x);
	else change(pos,val,2*x+1);
	a[x].sum=a[2*x].sum+a[2*x+1].sum;
	if(a[2*x].max>a[2*x+1].max) a[x].max=a[2*x].max;
	else a[x].max=a[2*x+1].max;
}
int findsum(int start,int end,int x)//x同上
{
	if(a[x].left==start && a[x].right==end)
		return a[x].sum;
//	int m=(a[x].left)+a[x].right/2;//由括号引发的血案，改了1 小时bug
	int m=(a[x].left+a[x].right)/2;
	if(m>=end) return findsum(start,end,2*x);
	else if(m<start) return findsum(start,end,2*x+1);
	else return findsum(start,m,2*x)+findsum(m+1,end,2*x+1);
}
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	build(1,n,1);
	for(i=1;i<10;i++)
	{
		printf("%d %d %d %d\n",a[i].left,a[i].right,a[i].max,a[i].sum);
	}
	change(5,1,1);
	for(i=1;i<10;i++)
	{
		printf("%d %d %d %d\n",a[i].left,a[i].right,a[i].max,a[i].sum);
	}
	scanf("%d%d",&j,&k);
	printf("%d\n",findsum(j,k,1));
	return 0;
}
