#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10;
struct opera{
	LL o,l,r;
}q[maxn];
LL lef[maxn<<2],mid[maxn<<2],rig[maxn<<2],lazy[maxn<<2];
LL sum[maxn<<2],a[maxn],b[maxn];
LL n,m,pos;
void buildnode(LL x,LL l,LL r){
	lef[x]=l;rig[x]=r;mid[x]=(l+r)>>1;
	if(l==r)return;
	buildnode(x<<1,l,mid[x]);
	buildnode(x<<1|1,mid[x]+1,r);
}
void build(LL x,LL l,LL r){
	if(l==r){sum[x]=b[l];return;}
	build(x<<1,l,mid[x]);
	build(x<<1|1,mid[x]+1,r);
	sum[x]=sum[x<<1]+sum[x<<1|1];
}
void pushdown(LL x);
void update(LL x,LL l,LL r,LL v){
	if(lef[x]>=l&&rig[x]<=r){
		lazy[x]=v;
		sum[x]=v*(rig[x]-lef[x]+1);
		return;
	}
	if(lazy[x]!=-1)pushdown(x);
	if(l<=mid[x])update(x<<1,l,r,v);
	if(r>mid[x])update(x<<1|1,l,r,v);
	sum[x]=sum[x<<1]+sum[x<<1|1];
}
void pushdown(LL x){
	if(lef[x]==rig[x]){lazy[x]=0;return;}
	update(x<<1,lef[x],rig[x],lazy[x]);
	update(x<<1|1,lef[x],rig[x],lazy[x]);
	lazy[x]=-1;
	sum[x]=sum[x<<1]+sum[x<<1|1];
}
LL query(LL x,LL l,LL r){
	if(lef[x]>=l&&rig[x]<=r)return sum[x];
	if(lazy[x]!=-1)pushdown(x);
	LL ans=0;
	if(l<=mid[x])ans+=query(x<<1,l,r);
	if(r>mid[x])ans+=query(x<<1|1,l,r);
	return ans;
}
void process(){
	LL i,j;
	for(i=0;i<m;i++){
		j=query(1,q[i].l,q[i].r);
		update(1,q[i].l,q[i].r,0);
		if(q[i].o)update(1,q[i].l,q[i].l+j-1,1);
		else update(1,q[i].r-j+1,q[i].r,1);
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	LL i,j,k;
	cin>>n>>m;pos=n/2+1;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=0;i<m;i++){
		cin>>j>>k;
		if(j<k)q[i]=(opera){0,j,k};
		else q[i]=(opera){1,k,j};
	}
	LL l=1,r=n+1,mid;
	buildnode(1,1,n);
	while(l!=r){
		mid=(l+r+1)>>1;
		for(i=1;i<=n;i++)b[i]=(a[i]>=mid?1:0);
		memset(lazy,-1,sizeof(lazy));
		build(1,1,n);
		process();
		if(query(1,pos,pos))l=mid;
		else r=mid-1;
	}
	cout<<r<<endl;
	return 0;
}