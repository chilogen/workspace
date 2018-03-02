#include<stdio.h>
typedef struct
{
	int left,right,data,sum;
	int last;//*--1,+--2.others--0
}tree;
tree a[100001];
int  b[100001],p;

void build(int start,int end,int x)
{
	a[x].left=start;	a[x].right=end;
	if(start==end)
	{
		a[x].data=1;
		a[x].sum=b[start]%p;
		a[x].last=0;
		return ;
	}
	int m=(start+end)/2;
	build(start,m,2*x);	build(m+1,end,2*x+1);
	a[x].sum=(a[2*x].sum%p+a[2*x+1].sum%p)%p;
	a[x].data=0;
	a[x].last=0;
}

void update1(int start,int end,int c,int x)//*x
{
	if(a[x].left==start&&a[x].right==end)
	{
		if(a[x].last==0) {a[x].data=c;	a[x].last=1;}
		if(a[x].last==1) a[x].data*=c;
		if(a[x].last==2)
		{
			a[2*x].data=a[x].data;	a[2*x+1].data=a[x].data;
			a[2*x].last=2;	a[2*x+1].last=2;
			a[2*x].sum=(a[2*x].sum+(a[2*x].right-a[2*x].left+1)*x%p)%p;
			a[2*x+1].sum=(a[2*x+1].sum+(a[2*x+1].right-a[2*x+1].left+1)*c%p)%p;
			a[x].data=c;	a[x].last=1;
		}
		return;
	}
	int m=(a[x].left+a[x].right)/2;
	if(m>=end)	update1(start,end,c,2*x);
	else if(m<start)	update1(start,end,c,2*x+1);
	else{update1(start,m,c,2*x);	update1(m+1,end,c,2*x+1);}
	a[x].sum=(a[2*x].sum%p+a[2*x+1].sum%p)%p;
	a[x].data=0;	a[x].last=0;
}
void update2(int start,int end,int c,int x)//+c
{
	if(a[x].left==start&&a[x].right==end)
	{
		if(a[x].last==0) {a[x].data=c;	a[x].last=2;}
		if(a[x].last==2) a[x].data+=c;
		if(a[x].last==1)
		{
			int i=(start+end)/2;
			update1(start,i,c,2*x);	update1(i+1,end,c,2*x+1);
			a[x].data=c;	a[x].last=2;
			a[x].sum=(a[2*x].sum%p+a[2*x+1].sum%p)%p;
		}
		return ;
	}
	int m=(a[x].left+a[x].right)/2;
	if(m>=end)	update2(start,end,c,2*x);
	else if(m<start)  update2(start,end,c,2*x+1);
	else{update2(start,m,c,2*x);	update2(m+1,end,c,2*x+1);}
	a[x].sum=(a[2*x].sum%p+a[2*x+1].sum%p)%p;
	a[x].data=0;	a[x].last=0;
}

int find(int start,int end,int x)
{
	int i;
	 if(a[x].left==start&&a[x].right==end)
	 {
	 	if(a[x].last==0)	return a[x].sum;
	 	if(a[x].last==1)
	 	{
	 		i=(start+end)/2;
	 		update1(start,i,a[x].data,2*x);	update1(i+1,end,a[x].data,2*x+1);
			a[x].data=0;	a[x].last=0;
			a[x].sum=(a[2*x].sum%p+a[2*x+1].sum%p)%p;
			return a[x].sum;
	 	}
	 	if(a[x].last==2)
	 	{
	 		i=(start+end)/2;
	 		update2(start,i,a[x].data,2*x);	update2(i+1,end,a[x].data,2*x+1);
	 		a[x].data=0;	a[x].last=0;
			a[x].sum=(a[2*x].sum%p+a[2*x+1].sum%p)%p;
			return a[x].sum;
	 	}
	 }
	 i=(start+end)/2;
	 if(i>=end)	return	find(start,end,2*x);
	 else if(i<start) return  find(start,end,2*x+1);
	 else return (find(start,i,2*x)+find(i+1,end,2*x+1))%p;
}

int main()
{
	int n,q,i,j,k,l;
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	build(1,n,1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&i);
		if(i==1)
		{
			scanf("%d%d%d",&i,&j,&k);
			update1(i,j,k,1);
		}
		else if(i==2)
		{
			scanf("%d%d%d",&i,&j,&k);
			update2(i,j,k,1);
		}
		else
		{
			scanf("%d%d",&i,&j);
			printf("%d\n",find(i,j,1));
		}
	}
	return 0;
}