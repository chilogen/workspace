#include <bits/stdc++.h>
using namespace std;
#define MAXN 50010
#define reset(a,b)  memset(a,b,sizeof(a))
typedef long long LL;
struct query
{
    LL l,r,ind,a,b;
}q[MAXN];
LL color[MAXN],sum[MAXN],block[MAXN],n,m,up=0;
bool cmp1(query a,query b)
{
    if(block[a.l]==block[b.l])    return a.r<b.r;
    else return block[a.l]<block[b.l];
}
bool cmp2(query a,query b)
{
    return a.ind<b.ind;
}

void updata(LL x,LL flag)
{
    LL j;
    if(x==0)    return;
    j=sum[color[x]];
    up-=j*(j-1)/2;
    j+=flag;
    up+=j*(j-1)/2;
    sum[color[x]]=j;
}

int main()
{
    LL i,j,k;
    reset(sum,0);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&color[i]);
        block[i]=i/sqrt(n);
    }
    for(i=0;i<m;i++)
    {
        scanf("%lld%lld",&q[i].l,&q[i].r);
        q[i].ind=i;
    }
    sort(q,q+m,cmp1);

    LL lp,rp;   lp=rp=0;
    for(i=0;i<m;i++)
    {
        while(lp<q[i].l) updata(lp,-1),lp++;
        while(lp>q[i].l) updata(lp-1,1),lp--;
        while(rp<q[i].r) updata(rp+1,1),rp++;
        while(rp>q[i].r) updata(rp,-1),rp--;

        if(q[i].r==q[i].l)  q[i].a=0,q[i].b=1;

        j=q[i].r-q[i].l+1;
        q[i].a=up;
        q[i].b=j*(j-1)/2;
        j=__gcd(q[i].a,q[i].b);
        q[i].a/=j,q[i].b/=j;
    }
    sort(q,q+m,cmp2);

    for(i=0;i<m;i++)
    {
        printf("%lld/%lld\n",q[i].a,q[i].b);
    }
    return 0;
}