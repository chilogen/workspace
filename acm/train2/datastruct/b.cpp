#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e6;
struct node{
	LL left,right,sum,lazy;
	node(){left=right=sum=lazy=0;}
}T[maxn<<2];
inline void pushdown(LL k){
	if(T[k].left!=T[k].right){
		T[k<<1].lazy+=T[k].lazy;
		T[(k<<1)+1].lazy+=T[k].lazy;
		T[k<<1].sum+=(T[k].lazy*(T[k<<1].right-T[k<<1].left+1));
		T[(k<<1)+1].sum+=(T[k].lazy*(T[(k<<1)+1].right-T[(k<<1)+1].left+1));
	}
	else T[k].sum=T[k].lazy;
	T[k].lazy=0;
}
void build(LL k,LL l,LL r){
	LL mid=(l+r)>>1;
	T[k].left=l;	T[k].right=r;
	if(l==r)return;
	build(k<<1,l,mid);
	build((k<<1)+1,mid+1,r);
}
void update(LL k,LL l,LL r,LL v){
	if(T[k].left>=l&&T[k].right<=r){
		T[k].lazy+=v;
		T[k].sum+=(v*(T[k].right-T[k].left+1));
		return;
	}
	if(T[k].lazy!=0)pushdown(k);
	LL mid=(T[k].left+T[k].right)>>1;
	if(l<=mid)update(k<<1,l,r,v);
	if(r>mid)update((k<<1)+1,l,r,v);
	T[k].sum=T[k<<1].sum+T[(k<<1)+1].sum;
}
LL query(LL k,LL l,LL r){
	if(T[k].left>=l&&T[k].right<=r)return T[k].sum;
	if(T[k].lazy!=0)pushdown(k);
	LL mid=(T[k].left+T[k].right)>>1,ans=0;
	if(l<=mid)ans+=query(k<<1,l,r);
	if(r>mid)ans+=query((k<<1)+1,l,r);
	return ans;
}
int main(){
	LL n,m,o,l,r,v;
	cin>>n>>m;
	build(1,1,n);
	while(m--){
		cin>>o>>l>>r>>v;
		if(o==0)	update(1,l,r,v);
		else cout<<query(1,l,r)<<endl;
	}
	return 0;
}