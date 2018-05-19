#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

int area[200<<2];	//seg_tree1
double wid[200<<2]; //seg_tree2
double x[200<<1];
typedef struct 
{
	double l,r,h;
	int f;
}line;
bool cmp(const line &a,const line &b){return a.h<b.h;}
line l[200<<2];
map <double,int> m;

void pushup(int left,int right,int rt)
{
	if(area[rt]!=0)	wid[rt]=x[right+1]-x[left];
	else if(left==right)	wid[rt]=0;
	else	wid[rt]=wid[2*rt]+wid[2*rt+1];
}
void update(int left,int right,int flag,int rt,int start,int end)
{
	if(start>=left&&end<=right)
	{
		area[rt]+=flag;
		pushup(start,end,rt);
		return ;
	}
	int m=(start+end)/2;
	if(m>=left) update(left,right,flag,2*rt,start,m);
	if(m<right)	 update(left,right,flag,2*rt+1,m+1,end);
	pushup(start,end,rt);
	return;
}

int main()
{
	int n,i,j,k;
	double x1,x2,y1,y2;
	double ans=0;
//	freopen("abc","r",stdin);
	while(1)
	{
		scanf("%d",&n);
		memset(area,0,800*sizeof(int));
		memset(wid,0,800*sizeof(double));
		memset(x,0,400*sizeof(double));
		ans=0;
		if(n==0)	break;
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			l[2*i-1].l=x1;	l[2*i-1].r=x2;	l[2*i-1].h=y1;	l[2*i-1].f=1;
			l[2*i].l  =x1;	l[2*i].r  =x2;	l[2*i].h  =y2;	l[2*i].f  =-1;
			x[2*i-1]=x1;	x[2*i]=x2;
		}
		sort(l,l+2*i-1,cmp);	sort(x,x+2*i-1);
		for(j=1;j<2*i+1;j++)	m[x[j]]=j;
		for(j=1;j<=2*n;j++)
		{
			int left=m[l[j].l],right=m[l[j].r]-1;
			if(right>=left)
			{
				update(left,right,l[j].f,1,1,2*n);
				ans+=wid[1]*(l[j+1].h-l[j].h);
			}
		}
		printf("%.2lf\n",ans);
	}
//	fclose(stdout);
	return 0;
}