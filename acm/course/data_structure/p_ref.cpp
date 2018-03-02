#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
struct data
{
    double x1,x2,y;
    int flag;
    }a[801];
double ha[201];
double sum[801];
int col[801];
inline bool cp(data a,data b){return a.y<b.y;}
void pushup(int size,int l,int r)
{
    if(col[size])sum[size]=ha[r+1]-ha[l];
    else if(l==r)sum[size]=0;
    else sum[size]=sum[size*2]+sum[size*2+1];
}
void update(int L,int R,int flag,int l,int r,int size)
{
    if(L<=l&&R>=r)
    {
        col[size]+=flag;
        pushup(size,l,r);
        return;
    }
    int m=(l+r)/2;
    if(L<=m)update(L,R,flag,l,m,size*2);
    if(R>m)update(L,R,flag,m+1,r,size*2+1);
    pushup(size,l,r);
}
int main()
{
    int n;
    while(cin>>n)
    {
    if(n==0) break;
    double x1,y1,x2,y2;
    for(int i=1;i<=n;i++)
    {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            a[2*i-1].x1=a[2*i].x1=x1;
            a[2*i-1].x2=a[2*i].x2=x2;
            a[2*i-1].y=y1;a[2*i].y=y2;
            a[2*i-1].flag=1;a[2*i].flag=-1;
            ha[2*i-1]=x1;ha[2*i]=x2;
            }
        sort(a+1,a+2*n+1,cp);sort(ha+1,ha+2*n+1);
        memset(col,0,sizeof(col));
        memset(sum,0,sizeof(sum));
        double ans=0;
        for(int i=1;i<=2*n;i++)
        {
            int l=lower_bound(ha+1,ha+2*n+1,a[i].x1)-ha;
            int r=lower_bound(ha+1,ha+2*n+1,a[i].x2)-ha-1;
            if(l<=r)update(l,r,a[i].flag,1,2*n,1);
            ans+=sum[1]*(a[i+1].y-a[i].y);
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}