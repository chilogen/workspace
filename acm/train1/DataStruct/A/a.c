#include<stdio.h>
#define MAXN 50000
struct tree
{
	int left;  //该段左端点
	int right; //右端点
	int max;   //该段保存的值
	int min;
}a[MAXN*4];//用一个结构体保存线段树
int b[MAXN];
void build(int start ,int end,int x)//x 代表父节点，初次代1，以1为根节点
{
	a[x].left=start;
	a[x].right=end;
	if(start==end)//递归到叶子节点，可以开始往里存东西了
	{
		a[x].max=b[start];
		a[x].min=b[start];
		return ;
	}
	int m=(start+end)/2;
	build(start,m,2*x); build (m+1,end,2*x+1);//递归分别建立左右子树
    /*根据左右子树的值和相应规则得到父节点的值*/
	if(a[2*x].max>a[2*x+1].max) a[x].max=a[2*x].max;
	else a[x].max=a[2*x+1].max;
	if(a[2*x].min>a[2*x+1].min) a[x].min=a[2*x+1].min;
	else a[x].min=a[2*x].min;
}//建树代码

/*void change(int pos,int val,int x)//x含义同上
{
	if(a[x].left==a[x].right)//递归到叶子节点
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
}*/
//和建树过程是一样的，都等同于往某点赋值
int max(int a,int b)
{
	if(a>b) return a;
	return b;
}
int min(int a,int b)
{
	if(a>b) return b;
	return a;
}
int findmax(int start,int end,int x)//x同上
{
	if(a[x].left==start && a[x].right==end)//要查询的结果保存在该节点
		return a[x].max;
	int m=(a[x].left+a[x].right)/2;//求分界点
	if(m>=end) return findmax(start,end,2*x);//要查询的结果保存在左子树
	else if(m<start) return findmax(start,end,2*x+1);//要查询的结果保存在右子树
	else return max(findmax(start,m,2*x),findmax(m+1,end,2*x+1));//分别保存在左右子树
}
int findmin(int start,int end,int x)//x同上
{
	if(a[x].left==start && a[x].right==end)
		return a[x].min;
	int m=(a[x].left+a[x].right)/2;
	if(m>=end) return findmin(start,end,2*x);
	else if(m<start) return findmin(start,end,2*x+1);
	else return min(findmin(start,m,2*x),findmin(m+1,end,2*x+1));
}
int main()
{
	int n,i,j,k,l;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	build(1,n,1);
	while(k--)
	{
		scanf("%d%d",&j,&l);
		printf("%d\n",findmax(j,l,1)-findmin(j,l,1));
	}
	return 0;
}
