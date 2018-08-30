#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL base=6,maxn=2*base;

LL ind[maxn],cnt=0,deg[maxn],lef[maxn],rig[maxn];
LL son[maxn][2];
double len[maxn];
double trie[maxn]={0};
double w[maxn];

LL lowbit(LL x){return x&(-x);}

void update(LL x,double v1,double v2){
	LL i;
	for(i=x;i<maxn;i+=lowbit(i))trie[i]-=v1;
	for(i=x;i<maxn;i+=lowbit(i))trie[i]+=v1;
}

double sum(LL l){
	double ans=0;
	LL i;
	for(i=l;i>0;i-=lowbit(i))ans+=trie[i];
	return ans;
}

void query(LL x){
	double dw=sum(ind[x]-1)-sum(lef[x]-1);
	double lw=sum(rig[x])-sum(lef[x]-1);
	double rw=dw-lw;
	double ans=len[x]*rw/dw;
	printf("%.14lf\n",ans);
}	

LL dfs(LL x){
	LL l=maxn;
	if(son[x][0]!=-1)l=min(l,dfs(son[x][0]));
	rig[x]=cnt;
	if(son[x][1]!=-1)l=min(l,dfs(son[x][1]));
	ind[x]=++cnt;
	lef[x]=min(l,ind[x]);
	return ind[x];
}

void solve(){
	LL n,q,i,j,k,l;
	memset(son,-1,sizeof(son));
	scanf("%lld%lld",&n,&q);
	for(i=1;i<=n+1;i++)scanf("%lf",&w[i]);
	for(i=base+1;i<=base+n;i++){
		scanf("%lf%lld%lld",&len[i],&j,&k);
		j+=base;k+=base;
		son[i][0]=j;
		son[i][1]=k;
		deg[j]++;deg[k]++;
	}
	for(i=base+1;i<=base+n;i++)if(deg[i]==0)break;
	dfs(i);
	for(i=1;i<n;i++){
		j=ind[i];
		update(j,0,w[i]);
	}
	for(i=0;i<q;i++){
		scanf("%lld%lld",&j,&k);
		if(j==2)query(ind[k]);
		else{
			scanf("%lld",&l);
			k=ind[k];
			update(k,w[i],l);
			w[i]=l;
		}
	}
}

int main(){
	solve();
	return 0;
}