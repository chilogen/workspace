#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=5e4+10;

double w[maxn],bw[maxn],len[maxn];
LL wfat[maxn],bfat[maxn],son[maxn][2],deg[maxn]={0};


void matain(LL x){
	LL l=son[x][0],r=son[x][1];
	double lw,rw;
	if(l<0)lw=w[abs(l)];
	else{
		matain(son[x][0]);
		lw=bw[l];
	}
	if(r<0)rw=w[abs(r)];
	else{
		matain(son[x][1]);
		rw=bw[r];
	}
	bw[x]=lw+rw;
}

double gw(LL x,LL y){
	double ans;
	if(son[x][y]<0)ans=w[-son[x][y]];
	else ans=bw[son[x][y]];
	return ans;
}

void query(LL x){
	double ans,rw;
	rw=gw(x,1);
	ans=len[x]*rw/bw[x];
	printf("%.14lf\n",ans);
}


void update(LL x,double v){
	LL j;
	double lw,rw;
	j=wfat[x];w[x]=v;
	lw=gw(j,0);rw=gw(j,1);
	bw[j]=lw+rw;
	j=bfat[j];
	while(j!=-1){
		lw=gw(j,0);rw=gw(j,1);
		bw[j]=lw+rw;
		j=bfat[j];
	}
}

void solve(){
	LL n,q,i,j,k,l;
	scanf("%lld%lld",&n,&q);
	for(i=1;i<=n+1;i++)scanf("%lf",&w[i]);
	for(i=1;i<=n;i++){
		scanf("%lf%lld%lld",&len[i],&j,&k);
		son[i][0]=j;son[i][1]=k;
		if(j<0)wfat[-j]=i;
		else bfat[j]=i;
		if(k<0)wfat[-k]=i;
		else bfat[k]=i;
		if(j>0)deg[j]++;
		if(k>0)deg[k]++;
	}
	for(i=1;i<=n;i++)if(deg[i]==0)break;
	matain(i);
	bfat[i]=-1;
	for(i=0;i<q;i++){
		scanf("%lld%lld",&j,&k);
		if(j==2)query(k);
		else{
			scanf("%lld",&l);
			update(k,l);
		}
	}
}

int main(){
	solve();
	return 0;
}