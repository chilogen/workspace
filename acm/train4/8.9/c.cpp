#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10;

LL n,m;

LL DFN[maxn],low[maxn],cnt=0,c,ans=0;
bool vis[maxn],inStack[maxn];///每次使用要清空
vector <LL> edge[maxn];
stack <LL> st;
void dfs(LL u,LL pre)///该例为无向图，pre保证没有n为2的环，可初始化为-1
{
	LL k;
    vis[u]=1;
    DFN[u]=low[u]=++cnt;
    st.push(u);
    inStack[u]=1;
    LL minn=DFN[u];
    if(edge[u].size()>0)
    {
        for(LL i=0;i<(LL)edge[u].size();i++)
        {
            LL v=edge[u][i];
            if(v==pre) continue;
            if(!vis[v])
            {
                dfs(v,u);
            }
            if(inStack[v])
                minn=min(low[v],minn);
        }
    }
    low[u]=minn;
    if(low[u]==DFN[u])
    {
    	c=0;
        while(1)
        {
            int x=st.top();
            st.pop();
           	c++;
            inStack[x]=0;
            low[x]=DFN[u];
            if(x==u) break;
        }
        k=c*(c-1)/2;
        c-=2;
        if(c>=2){
        	ans+=k*(c*(c-1))/2;
        }
    }
} 
void connect(LL x,LL y){
	edge[x].push_back(y);
}
int main(){
	LL i,j,k;
	while(scanf("%lld%lld",&n,&m)!=EOF){
		ans=0;
		for(i=0;i<n;i++)edge[i].clear();
		memset(vis,0,sizeof(vis));
		memset(inStack,0,sizeof(inStack));
		for(i=0;i<m;i++){
			cin>>j>>k;
			connect(j,k);
		}
		dfs(1,-1);
		cout<<ans<<endl;
	}
	return 0;
}