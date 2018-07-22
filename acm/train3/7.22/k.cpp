#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10;
struct node{
	LL left,right,sum,lazy;
}T[maxn<<2];
struct opera{
	LL o,l,r;
}f[maxn];
LL a[maxn],b[maxn],n,k,m;
void build(LL x,LL l,LL r){
	T[x].left=l;T[x].right=r;T[x].lazy=-1;T[x].sum=0;
	if(l==r){
		T[x].sum=(b[l]==0?0:1);
		return;
	}
	LL mid=(l+r)>>1;
	build(x<<1,l,mid);
	build((x<<1)+1,mid+1,r);
	T[x].sum=T[x<<1].sum+T[(x<<1)+1].sum;
}
void update(LL x,LL l,LL r,LL v);
void pushdown(LL x){
	LL mid=(T[x].left+T[x].right)>>1;
	update(x<<1,T[x].left,mid,T[x].lazy);
	update((x<<1)+1,mid+1,T[x].right,T[x].lazy);
	T[x].lazy=-1;
}
void update(LL x,LL l,LL r,LL v){
	if(r<l)return;
	if(T[x].left>=l&&T[x].right<=r){
		T[x].sum=(T[x].right-T[x].left+1)*v;
		T[x].lazy=v;
		return;
	}
	if(T[x].lazy!=-1)pushdown(x);
	LL mid=(T[x].left+T[x].right)>>1;
	if(l<=mid)update(x<<1,l,r,v);
	if(r>mid)update((x<<1)+1,l,r,v);
	T[x].sum=T[x<<1].sum+T[(x<<1)+1].sum;
}
LL query(LL x,LL l,LL r){
	if(T[x].left>r||T[x].right<l)return 0;
	if(T[x].left>=l&&T[x].right<=r)return T[x].sum;
	if(T[x].lazy!=-1)pushdown(x);
	return query(x<<1,l,r)+query((x<<1)+1,l,r);
}
bool solve(){
	LL i,j;
	for(i=0;i<m;i++){
		j=query(1,f[i].l,f[i].r);
		update(1,f[i].l,f[i].r,0);
		if(f[i].o)update(1,f[i].l,f[i].l+j-1,1);
		else update(1,f[i].r-j+1,f[i].r,1);
	}
	return query(1,k,k)==1;
}
int main(){
	LL i,l,r,mid,t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=0;i<m;i++)cin>>f[i].o>>f[i].l>>f[i].r;
		cin>>k;		
		l=1;r=n+1;
		while(r>l){
			mid=(l+r+1)>>1;
			for(i=1;i<=n;i++)b[i]=(a[i]>=mid?1:0);
			build(1,1,n);
			if(solve())l=mid;
			else r=mid-1;
		}
		cout<<r<<endl;
	}
	return 0;
}