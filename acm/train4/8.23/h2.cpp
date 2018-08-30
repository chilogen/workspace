#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=4e5+10;

struct val{
	LL x,y,z;
};

LL son[maxn][2],lef[maxn][2],rig[maxn],deg[maxn]={0};
LL ind[maxn],cnt;
double w[maxn],t[maxn],len[maxn];

LL lowbit(LL x){return x&(-x);}

LL sum(LL l){
	LL i;
	double ans=0;
	for(i=l;i>0;i-=lowbit(i))ans+=t[i];
	return ans;
}

void update(LL x,double old,double ne){
	LL i;
	for(i=x;i<maxn;i+=lowbit(i))t[i]-=old;
	for(i=x;i<maxn;i+=lowbit(i))t[i]+=ne;
}

void query(LL x){
	double dw=sum(rig[x])-sum(lef[x][0]-1);
	double lw=sum(lef[x][1])-sum(lef[x][0]-1);
	double rw=dw-lw;
	double ans=len[x]*rw/dw;
	printf("%.14lf\n",ans);
}
void dfs(LL x){
	if(son[x][0]<0){
		ind[-son[x][0]]=++cnt;
		lef[x][0]=lef[x][1]=ind[-son[x][0]];
	}
	else dfs(son[x][0]);
	if(son[x][1]<0){
		ind[-son[x][1]]=++cnt;
		rig[x]=ind[-son[x][1]];
	}
	else dfs(son[x][1]);
	if(lef[x][0]==-1)lef[x][0]=lef[son[x][0]][0];
	if(lef[x][1]==-1)lef[x][1]=rig[son[x][0]];
	if(rig[x]==-1)rig[x]=rig[son[x][1]];
}

double now[maxn]={0};

void solve(){
	memset(lef,-1,sizeof(lef));
	memset(rig,-1,sizeof(rig));
	LL n,q,i,j,k,l;
	scanf("%lld%lld",&n,&q);
	for(i=1;i<=n+1;i++)
		scanf("%lf",&w[i]);
	for(i=1;i<=n;i++){
		scanf("%lf%lld%lld",&len[i],&j,&k);
		son[i][0]=j;son[i][1]=k;
		if(j>0)deg[j]++;
		if(k>0)deg[k]++;
	}
	for(i=1;i<=n;i++)if(deg[i]==0)break;
	dfs(i);
	for(i=1;i<=n+1;i++){
		update(ind[i],0,w[i]);
		now[ind[i]]=w[i];
	}
	for(i=0;i<q;i++){
		scanf("%lld%lld",&j,&k);
		if(j==2)query(k);
		else{
			k=ind[k];
			scanf("%lld",&l);
			update(k,now[k],l);
			now[k]=l;
		}
	}
}

int main(){
	solve();
	return 0;
}