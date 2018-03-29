

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define debug puts("======")
typedef long long ll;
using namespace std;
const int maxn=10005;
int n,q;
int tmp;
ll m;
char str[10];
int p[50];
int cnt;
struct Node
{
    int c[11];
    ll a;
}node[maxn<<2];
Node add[maxn<<2];
int no[maxn<<2];
void pre(int u)
{
    cnt=0;
    for(int i=2;i*i<=u;i++) {
        if(u%i==0)
            p[cnt++]=i;
        while(u&&u%i==0) {
            u/=i;
        }
    }
    if(u>1)
        p[cnt++]=u;
}
ll powMod(ll a,ll b)
{
    if(b==0) return 1;
    ll ans=powMod(a,b/2);
    ans=ans*ans%m;
    if(b&1)
        ans=ans*a%m;
    return ans;
}
ll ExGcd(ll a, ll b, ll &x, ll &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll r = ExGcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - a / b * y;
    return r;
}
void pushUp(int rt)
{
    node[rt].a=node[rt<<1].a*node[rt<<1|1].a%m;
    for(int i=0;i<cnt;i++) {
        node[rt].c[i]=node[rt<<1].c[i]+node[rt<<1|1].c[i];
    }
}
void build(int l,int r,int rt)
{
    no[rt]=0;
    add[rt].a=1;
    for(int i=0;i<cnt;i++)
        add[rt].c[i]=0;
    if(l==r) {
        scanf("%d",&tmp);
        for(int i=0;i<cnt;i++) {
            node[rt].c[i]=0;
            while(tmp && tmp%p[i]==0) {
                tmp/=p[i];
                node[rt].c[i]++;
            }
        }
        node[rt].a=tmp;
        return;
    }
    int m=((l+r)>>1);
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushUp(rt);
}
void pushDown(int l,int r,int rt)
{
    if(no[rt]==0) return;
    no[rt]=0;
    int mm=((l+r)>>1);
    for(int i=0;i<cnt;i++) {
        add[rt<<1].c[i]+=add[rt].c[i];
        add[rt<<1|1].c[i]+=add[rt].c[i];
        node[rt<<1].c[i]+=add[rt].c[i]*(mm-l+1);
        node[rt<<1|1].c[i]+=add[rt].c[i]*(r-mm);
        add[rt].c[i]=0;
    }
    add[rt<<1].a=add[rt<<1].a*add[rt].a%m;
    add[rt<<1|1].a=add[rt<<1|1].a*add[rt].a%m;
    node[rt<<1].a=node[rt<<1].a*powMod(add[rt].a,mm-l+1)%m;
    node[rt<<1|1].a=node[rt<<1|1].a*powMod(add[rt].a,r-mm)%m;
    add[rt].a=1;
    no[rt<<1]=no[rt<<1|1]=1;
}
int num[20];
void update(int L,int R,int c,int l,int r,int rt,int ty)
{
    if(L<=l&&R>=r) {
        int u=c;
        for(int i=0;i<cnt;i++) {
            num[i]=0;
           // debug;
            while(u && u%p[i]==0) {
                u/=p[i];
                num[i]++;
              //  debug;
            }
        }
       // debug;
        no[rt]=1;
        if(ty==0) {
            for(int i=0;i<cnt;i++) {
                add[rt].c[i]+=num[i];
                node[rt].c[i]+=num[i]*(r-l+1);
            }
            add[rt].a=add[rt].a*u%m;
            node[rt].a=node[rt].a*powMod(u,r-l+1)%m;
        }
        else {
            for(int i=0;i<cnt;i++) {
                add[rt].c[i]-=num[i];
                node[rt].c[i]-=num[i]*(r-l+1);
            }
            ll px,py;
            ExGcd(u, m, px, py); //求u的逆元，px为逆元
            px%=m;
            if(px<0) px+=m;
            add[rt].a=add[rt].a*px%m;
            node[rt].a=node[rt].a*powMod(px,r-l+1)%m;
        }
        return;
    }
    pushDown(l,r,rt);
    int m=(l+r)>>1;
    if(L<=m)
        update(L,R,c,l,m,rt<<1,ty);
    if(R>m)
        update(L,R,c,m+1,r,rt<<1|1,ty);
    pushUp(rt);
}
ll query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r) {
        ll ans=1;
        for(int i=0;i<cnt;i++) {
            ans=ans*powMod(p[i],node[rt].c[i])%m;
        }
        ans=ans*node[rt].a%m;
        return ans;
    }
    pushDown(l,r,rt);
    ll ans=1;
    int mm=(l+r)>>1;
    if(L<=mm)
        ans=ans*query(L,R,l,mm,rt<<1)%m;
    if(R>mm)
        ans=ans*query(L,R,mm+1,r,rt<<1|1)%m;
    return ans;
}
int main()
{
    int t;
    int a,b,c;
    int cas=1;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%lld",&n,&m);
        pre(m);
        build(1,n,1);
        scanf("%d",&q);
        printf("Case #%d:\n",cas++);
        while(q--) {
            scanf("%s",str);
            if(str[0]=='M') {
                scanf("%d%d%d",&a,&b,&c);
                update(a,b,c,1,n,1,0);
            }
            else if(str[0]=='D') {
                scanf("%d%d%d",&a,&b,&c);
                update(a,b,c,1,n,1,1);
            }
            else {
                scanf("%d%d",&a,&b);
                printf("%lld\n",query(a,b,1,n,1));
            }
        }
    }
    return 0;
}

