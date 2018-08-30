#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=110;
LL t,n,m,ans;
LL use[maxn],deg[maxn],vis[maxn];
vector<LL>edge[maxn],v;
LL dfs(LL x){
    use[x]=1;
    v.push_back(x);
    LL i,k;
    for(i=0,k=0;i<(LL)edge[x].size();i++){
        if(use[edge[x][i]])continue;
        k+=dfs(edge[x][i]);
    }
    return k+1;
}
void dfs2(LL x,LL y){
    LL i;
    vis[x]=1;
    for(i=0;i<(LL)edge[x].size();i++){
        if(edge[x][i]==y)continue;
        deg[edge[x][i]]--;
        if(!vis[edge[x][i]])dfs2(edge[x][i],y);
    }
}
void check(LL x){
    if(x==0||x%2!=0)return;
    LL d1=x/2-1,d2=x/2;
    LL cnt[2]={0};
    LL i,j,k=-1;
    for(i=0;i<(LL)v.size();i++){
        if(deg[v[i]]==d1)cnt[0]++;
        if(deg[v[i]]==d2){
            cnt[1]++;
            swap(j,k);
            j=v[i];
        }
    }
    //if(cnt[0]==x-2&&cnt[1]==2){ans++;return;}
    if(cnt[0]!=x-2||cnt[1]!=2)return;
    memset(vis,0,sizeof(vis));
    dfs2(j,k);
    for(i=0,j=0;i<(LL)v.size();i++)if(deg[v[i]]==0)j++;
    if(j!=x/2-1)return;
    ans++;
}
void connct(LL x,LL y){
    edge[x].push_back(y);
    edge[y].push_back(x);
    deg[x]++;
    deg[y]++;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    LL i,j,k,Kase=1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<Kase++<<": ";
        cin>>n>>m;
        memset(use,0,sizeof(use));
        memset(deg,0,sizeof(deg));
        for(i=1;i<=n;i++)edge[i].clear();
        ans=0;
        for(i=0;i<m;i++){
            cin>>j>>k;
            connct(j,k);
        }
        for(i=1;i<=n;i++){
            if(!use[i]){
                v.clear();
                j=dfs(i);
                check(j);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}