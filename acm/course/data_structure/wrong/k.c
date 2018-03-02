#include<stdio.h>
typedef struct
{
	int left;
	int right;
	long long int maxl,maxm,maxr;
	int flagl,flagm,flagr;
}tree;
tree a[100001];
long long int b[100001];
int max(long long int a,long long int b)
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
		a[x].maxl=b[start];
		a[x].maxm=b[start];
		a[x].maxr=b[start];
		a[x].flagl=1;
		a[x].falgm=1;
		a[x].flagr=1;
		return ;
	}
	int m=(start+end)/2;
	build(start,m,2*x); build (m+1,end,2*x+1);
	a[x].flagl=1;	a[x].falgm=1;	a[x].flagr=a1;
	a[x].maxm=a[2*x].maxm+a[2*x+1].maxm;
	a[x].maxl=a[x].maxm;	a[x].maxr=a[x].maxm;
	/*
	if(a[x].flagl==1)	a[x].maxl=a[2*x].maxl; //1
	if(a[2*x].flagr==1) a[x].maxr=a[2*x+1].maxr;// 1
	a[x].max=max(max(max(a[2*x].maxl,a[2*x+1].maxr),max(a[2*x].maxm,a[2*x+1].maxm)),i);*/
}
void brea(int k,int x)
{
	if(a[k].left==a[k].right)
	{
		a[k].maxl=0;
		a[k].maxm=0;
		a[k].maxr=0;
		a[k].flagl=0;
		a[k].flagm=0;
		a[k].flagr=0;
		return;
	}
	int m=(a[k].left+a[k].right)/2;
	if(x<=m) brea(2*k,x);
	else brea(2*k+1,x);
	a[x].flagl=a[2*x].flagl;	a[x].flagr=a[2*x+1].flagr;
	int i=-1;
	if(a[2*x].flagr==1&&a[2*x+1].flagl==0) i=a[2*x].maxr+a[2*x+1].maxl;
	int max;
	max=max(max(max(a[2*x].maxl,a[2*x].maxm),max(a[2*x+1].maxr),a[2*x+1].maxm),i);
	if(max==i)
	{
		a[x].maxm=max;
		
	}
int main()
{
	int n,i,j,k,l;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	build(1,n,1);
	while(n--)
	{
		scanf("%d",&i);
		brea(1,i);
		printf("%lld\n",a[1].max);
	}
	return 0;
}