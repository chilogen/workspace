/*
 * 题目：有一个HOOK，范围最大为1-100000，没格可能为 1、2、3，初始为1
 * 输入T,为数据组数，n,op分别为范围和操作数
 * 操作 (x,y,z)代表将(x,y)这一区间的值替换为z
 * 输出（1，n）范围上的和
 * */

/*
 *本题在于联系懒操作，添加一个delay标志，代表该段有更新，但本次不更新到叶子节点
 *当下次在更新该段中某一子段是，再根据这一标志对叶子节点更新
 */

#include <stdio.h>
typedef struct 
{
	int left,right;
	int sum;
	int delay;
}tree;
tree a[100001*4];
void build(int start,int end,int x)
{
	a[x].left=start;	a[x].right=end;
	if(start==end)
		{a[x].sum=1;	a[x].delay=0;}
	else
	{
		int m=(start+end)/2;
		build(start,m,2*x);	build(m+1,end,2*x+1);
		a[x].sum=a[2*x].sum+a[2*x+1].sum;
		a[x].delay=0;
	}
}//建树

void change(int start,int end,int z,int k)
{
	if(a[k].left>=start && a[k].right<=end)
	{
		a[k].delay=z;
		a[k].sum=(a[k].right-a[k].left+1)*z;
		return ;
	}//如果该段是要更新段的子段，则满足懒操作要求，设置delay标志

	if(a[k].delay!=0  &&  a[k].left!=a[k].right)
	{
		a[2*k].sum=(a[2*k].right-a[2*k].left+1)*a[k].delay;
		a[2*k].delay=a[k].delay;
		a[2*k+1].sum=(a[2*k+1].right-a[2*k+1].left+1)*a[k].delay;
		a[2*k+1].delay=a[k].delay;
		a[k].delay=0;
	}//如果第二次到达该段，且该段不是元段，则表明需要更新叶子节点

	int m=(a[k].left+a[k].right)/2;
	if(m>=end)
	{
		change(start,end,z,2*k);
		a[k].sum=a[2*k].sum+a[2*k+1].sum;
		return ;
	}

	else if(m<start)
	{
		change(start,end,z,2*k+1);
		a[k].sum=a[2*k].sum+a[2*k+1].sum;
		return ;
	}
	else
	{
		change(start,end,z,2*k);	change(start,end,z,2*k+1);
		a[k].sum=a[2*k].sum+a[2*k+1].sum;
		return ;
	}//递归寻找包含要更新段的叶子
}
int main()
{
	int c,x,y,z,n,op,i;
	scanf("%d",&c);
	for(i=1;i<=c;i++)
	{
		scanf("%d%d",&n,&op);
		build(1,n,1);
		while(op--)
		{
			scanf("%d%d%d",&x,&y,&z);
			change(x,y,z,1);
		}
		printf("Case %d: The total value of the hook is %d.\n",i, a[1].sum);
	}
	return 0;
}
