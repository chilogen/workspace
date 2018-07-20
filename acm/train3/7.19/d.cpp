#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10,inf=1e15;
vector<LL>e[maxn];
LL n,m,t,cnt[maxn];
struct node{
	LL l,r,lazy,mi;
}T[maxn<<4];
void build(LL x,LL a,LL b){
	T[x].l=a;T[x].r=b;T[x].lazy=0;
	if(a==b){
		T[x].mi=cnt[a];
		return;
	}
	LL mid=(a+b)>>1;
	build(x<<1,a,mid);
	build((x<<1)+1,mid+1,b);
	T[x].mi=min(T[x<<1].mi,T[(x<<1)+1].mi);
}
void pushdown(LL x);
void update(LL x,LL a,LL b,LL v){
	if(a>b)return;
	if(T[x].l>=a&&T[x].r<=b){
		T[x].lazy+=v;
		T[x].mi+=v;
		return;
	}
	if(T[x].lazy!=0)pushdown(x);
	LL mid=(T[x].l+T[x].r)>>1;
	if(a<=mid)update(x<<1,a,b,v);
	if(b>mid)update((x<<1)+1,a,b,v);
	T[x].mi=min(T[x<<1].mi,T[(x<<1)+1].mi);
}
void pushdown(LL x){
	if(T[x].l!=T[x].r){
		update(x<<1,T[x].l,T[x].r,T[x].lazy);
		update((x<<1)+1,T[x].l,T[x].r,T[x].lazy);
		T[x].mi=min(T[x<<1].mi,T[(x<<1)+1].mi);
	}
	T[x].lazy=0;
}
LL query(LL x){
	LL i;
	if(T[x].l==T[x].r){
		T[x].mi=inf;
		return T[x].r;
	}
	if(T[x].lazy!=0)pushdown(x);
	if(T[(x<<1)+1].mi==T[x].mi)i=query((x<<1)+1);
	else i=query(x<<1);
	T[x].mi=min(T[x<<1].mi,T[(x<<1)+1].mi);
	return i;
}
int main(){
	LL i,j,k;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++){
			cnt[i]=i-1;
			e[i].clear();
		}
		for(i=0;i<m;i++){
			scanf("%lld%lld",&j,&k);
			e[j].push_back(k);
			cnt[k]--;
		}
		build(1,1,n);
		for(i=0;i<n;i++){
			j=query(1);
			update(1,j+1,n,-1);
			for(k=0;k<(int)e[j].size();k++)update(1,e[j][k],e[j][k],1);
			printf("%lld ",j);
		}
		printf("\n");
	}
	return 0;
}