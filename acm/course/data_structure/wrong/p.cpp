#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct
{
	double l,r,h;
	int f;
}line;

inline bool cmp(const line &a,const line &b){return a.h<b.h;}

line	a[201];
int 	b[200<<2];
double	wid[200<<2];
double	x[201];

void updatew(int k,int start,int end)
{
	if(b[k]>0)	wid[k]+=x[end+1]-x[start];
	else if(b[k]==0)	wid[k]=0;
	else wid[k]=wid[2*k]+wid[2*k+1];
}

void updateb(int l,int r,int flag,int x,int start,int end)
{
	if(start>=l&&end<=r)
	{
		b[x]+=flag;
		updatew(x,start,end);
		return ;
	}
	int m=(start+end)/2;
	if(m>=r)	updateb(l,r,flag,2*x,start,m);
	else if(m<l)	updateb(l,r,flag,2*x+1,m+1,end);
	else	{updateb(l,r,flag,2*x,start,m);	updateb(l,r,flag,2*x+2,m+1,end);}
	updatew(x,start,end);
}
void init()
{
	memset(b,0,200<<2);
	memset(wid,0,200<<2);
}
int main()
{
	freopen("abc","r",stdin);
	int n,i,j;
	double x1,x2,y1,y2;
	double ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		a[2*i-1].l=x1;	a[2*i-1].r=x2;	a[2*i-1].h=y1;	a[2*i-1].f=1;
		a[2*i].l  =x1;	a[2*i].r  =x2;	a[2*i].h  =y2;	a[2*i].f  =-1;
		x[2*i-1]=x1;	x[2*i]=x2;
	}
	sort(a,a+2*i-1,cmp);	sort(x,x+2*i-1);
	init();
	for(i=1;i<=2*n;i++)
	{
		int l=lower_bound(x+1,x+2*n+1,a[i].l)-x;
		int r=lower_bound(x+1,x+2*n+1,a[i].r)-x-1;
		if(r>l)
		{
			updateb(l,r,a[i].f,1,1,2*n);
			ans+=wid[1]*(a[i+1].h-a[i].h);
		}
	}
	printf("%lf",ans);
	fclose(stdin);
	return 0;
}