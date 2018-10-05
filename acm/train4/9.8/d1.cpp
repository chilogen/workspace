#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1010;
const int MAXM = 10000+10;
LL n,m,s,e,k,t,dist[maxn];
struct node{
    LL x,v,f;
};
struct edge{
    LL to,v,l;
};
struct cmp{
    bool operator()(node a,node b){
        return a.v>b.v;
    }
};
struct cmp1{
    bool operator()(node a,node b){
        return a.f>b.f;
    }
};
// vector<edge>g[maxn],inv[maxn];
edge edges[MAXM], edges_inv[MAXM];
int size, size_inv;
int head[maxn], head_inv[maxn];

void add_edge(int u, int v, int w)
{
    edges[++size] = (edge){v, w, head[u]};
    head[u] = size;
}

void add_edge_inv(int u, int v, int w)
{
    edges_inv[++size_inv] = (edge){v, w, head_inv[u]};
    head_inv[u] = size_inv;
}

inline void dijk(){
    priority_queue<node,vector<node>,cmp>q;
    memset(dist,1,sizeof(LL)*(n+1));
    dist[e]=0;
    q.push((node){e,0,0});
    while(!q.empty()){
        node tn=q.top();q.pop();
        if(tn.v!=dist[tn.x])continue;
        // vector<edge>::iterator it=inv[tn.x].begin();

        // while(it!=inv[tn.x].end()){
        for(int lst = head_inv[tn.x]; lst; lst = edges_inv[lst].l)
        {
            //edge* it = &edges_inv[lst];
            if(dist[edges_inv[lst].to]>dist[tn.x]+edges_inv[lst].v){
                dist[edges_inv[lst].to]=dist[tn.x]+edges_inv[lst].v;
                q.push((node){edges_inv[lst].to,dist[edges_inv[lst].to],0});
            }
            // it++;
        }
    }
}

//LL cnt[maxn];


LL solve(){
    priority_queue<node,vector<node>,cmp1>q;
    cin>>s>>e>>k>>t;
    LL i,j,l,d;
    bool flag=false;
    // for(i=0;i<=n;i++){g[i].clear();inv[i].clear();}
    memset(head, 0, sizeof(head));
    memset(head_inv, 0, sizeof(head_inv));
    //memset(cnt,0,sizeof(cnt));
    size = 0;
    size_inv = 0;
    for(i=0;i<m;i++){
        cin>>j>>l>>d;
        add_edge(j, l, d);
        add_edge_inv(l, j, d);
        // g[j].push_back((edge){l,d});
        // inv[l].push_back((edge){j,d});
    }
    dijk();
    q.push((node){s,0,dist[s]});
    l=0;
    while(!q.empty()){
        node tn=q.top();q.pop();
        if(tn.x==e){
            k--;
            if((LL)q.size()>k)flag=true;
            if(k==0)return tn.v;
        }
        // vector<edge>::iterator it=g[tn.x].begin();
        // while(it!=g[tn.x].end())
        for(int lst = head[tn.x]; lst; lst = edges[lst].l)
        {
            //edge* it = &edges[lst];
            i=edges[lst].v+tn.v;j=i+dist[edges[lst].to];
            if(flag){
                if(j>l)continue;
            }
            else l=max(l,j);
            //if(cnt[edges[lst].to]>k)continue;
            //cnt[edges[lst].to]++;
            q.push((node){edges[lst].to,i,j});
            // it++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    LL x;
    while(cin>>n>>m){
        x=solve();
        if(x<=t)cout<<"yareyaredawa\n";
        else cout<<"Whitesnake!\n";
    }
    return 0;
}