#include <bits/stdc++.h>
#define LL long long
#define inf 1ll<<30
using namespace std;
 
const int maxn=30010,maxm=60010;
int vis[maxn],deep[maxn],f[maxn],size[maxn],head[maxn];
int n,m,K,cnt,sum,Dargen;
int ans1;LL ans2;
 
struct edge {int from,to,next,w;}e[maxm<<1];
 
namespace Prepare {
    int dis[maxn];
    vector<int> v[maxn];
    struct data {
        int num,w;
        friend bool operator < (const data a,const data b) {
            return a.w>b.w;
        }
    };
 
    void link(int u,int v,int w) {
        e[++cnt]=(edge){u,v,head[u],w};head[u]=cnt;
        e[++cnt]=(edge){v,u,head[v],w};head[v]=cnt;
    }
    void Dijkstra() {
        priority_queue<data> q;
        for (int i=1;i<=n;i++) dis[i]=inf;
        q.push((data){1,0});dis[1]=0;
        while (!q.empty()) {
            data x=q.top();q.pop();
            if (vis[x.num]) continue;
            vis[x.num]=1;
            for (int i=head[x.num];i;i=e[i].next)
                if (!vis[e[i].to] && dis[e[i].to]>x.w+e[i].w) {
                    dis[e[i].to]=x.w+e[i].w;
                    q.push((data){e[i].to,dis[e[i].to]});
                }
        }
        for (int i=1;i<=cnt;i++) {
            int uu=e[i].from,vv=e[i].to,ww=e[i].w;
            if (dis[uu]+ww==dis[vv]) v[uu].push_back(vv);
        }
    }
    void build(int x) {
        vis[x]=1;
        sort(v[x].begin(),v[x].end());
        int l=v[x].size();
        for (int i=0;i<l;i++) if (!vis[v[x][i]]) {
                link(x,v[x][i],dis[v[x][i]]-dis[x]);
                build(v[x][i]);
            }
    }
}
 
namespace NodeDivide {
    int D[maxn],d[maxn],cntd[maxn],cntD[maxn];
 
    void caldargen(int x,int fa) {
        size[x]=1;f[x]=0;
        for (int i=head[x];i;i=e[i].next) if (!vis[e[i].to] && e[i].to!=fa) {
                caldargen(e[i].to,x);
                size[x]+=size[e[i].to];
                f[x]=max(f[x],size[e[i].to]);
            }
        f[x]=max(f[x],sum-size[x]);
        if (f[x]<f[Dargen]) Dargen=x;
    }
    void caldeep(int x,int fa,int l) {
        if (d[deep[x]]<l) d[deep[x]]=l,cntd[deep[x]]=1;
        else if (d[deep[x]]==l) cntd[deep[x]]++;
        for (int i=head[x];i;i=e[i].next) if (e[i].to!=fa && !vis[e[i].to]) {
                deep[e[i].to]=deep[x]+1;
                caldeep(e[i].to,x,l+e[i].w);
            }
    }
    void work(int x) {
        vis[x]=1;
        for (int i=head[x];i;i=e[i].next) if (!vis[e[i].to]) {
                deep[e[i].to]=1;
                caldeep(e[i].to,0,e[i].w);
                for (int j=1;d[j] && j<K;j++) {
                    if (ans1<D[K-1-j]+d[j]) {
                        ans1=D[K-1-j]+d[j];
                        ans2=(LL)cntD[K-1-j]*cntd[j];
                    }
                    else if (ans1==D[K-1-j]+d[j]) ans2+=(LL)cntD[K-1-j]*cntd[j];
                }
                for (int j=1;d[j];j++) {
                    if (D[j]<d[j]) D[j]=d[j],cntD[j]=cntd[j];
                    else if (D[j]==d[j]) cntD[j]+=cntd[j];
                    d[j]=cntd[j]=0;
                }
            }
        for (int i=1;D[i];i++) D[i]=cntD[i]=0;
        for (int i=head[x];i;i=e[i].next) if (!vis[e[i].to] && size[e[i].to]>=K) {
                Dargen=0;sum=size[e[i].to];
                caldargen(e[i].to,0);
                work(Dargen);
            }
    }
    void Init() {
        memset(vis,0,sizeof(vis));
        f[0]=inf;sum=n;cntD[0]=1;
        Dargen=0;caldargen(1,0);
        work(Dargen);
    }
}
 
int main() {
    scanf("%d%d%d",&n,&m,&K);
    for (int u,v,w,i=1;i<=m;i++) {
        scanf("%d%d%d",&u,&v,&w);
        Prepare::link(u,v,w);
    }
    Prepare::Dijkstra();
    memset(head,0,sizeof(head));
    memset(vis,0,sizeof(vis));
    cnt=0;
    Prepare::build(1);
    NodeDivide::Init();
    printf("%d %lld",ans1,ans2);
    return 0;
}