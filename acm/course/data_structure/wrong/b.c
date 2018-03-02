#include<stdio.h>
#define MAXN 100000
struct tree
{
	int left;
	int right;
	int max;
	int flag;
}a[MAXN*4];
int b[MAXN];
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
void build(int start ,int end,int x)
{
	a[x].left=start;
	a[x].right=end;
	if(start==end)
	{
		a[x].max=b[start];
		a[x].flag=b[start];
		return ;
	}
	int m=(start+end)/2;
	build(start,m,2*x); build (m+1,end,2*x+1);
	if(a[2*x].flag==1) a[x].max=a[2*x].max+a[2*x+1].max;
	else a[x].max=max(a[2*x].max,a[2*x+1].max);
	a[x].flag=a[2*x+1].flag;
}
void change(int start,int end,int x)
{
	if(a[x].left==a[x].right)
	{
		if(a[x].max==1){a[x].max=0;a[x].flag=0;}
		else {a[x].max=1;a[x].flag=1;}
		return ;
	}
	int m=(a[x].left+a[x].right)/2;
	if(m>=end) change(start,end,2*x);
	else if(m<start) change(start,end,2*x+1);
	else {change(start,m,2*x);change(m+1,end,2*x+1);}
	if(a[2*x].flag==1) a[x].max=a[2*x].max+a[2*x+1].max;
	else a[x].max=max(a[2*x].max,a[2*x+1].max);
	a[x].flag=a[2*x+1].flag;
}
int find(int start,int end,int x)
{
	if(a[x].left==start && a[x].right==end)
		return a[x].max;
	int m=(a[x].left+a[x].right)/2;
	if(m>=end) return find(start,end,2*x);
	else if(m<start) return find(start,end,2*x+1);
	else if(a[2*x].flag==1)return find(start,m,2*x)+find(m+1,end,2*x+1);
	else return max(find(start,m,2*x),find(m+1,end,2*x+1));
}
int main()
{
	int n,i,j,k,l;
	freopen("abc","r",stdin); 
	freopen("a.txt","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	build(1,n,1);
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d%d",&i,&j,&l);
		if(i==1) change(j,l,1);
		else printf("%d\n",find(j,l,1));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
