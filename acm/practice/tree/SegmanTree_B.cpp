#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
const Int maxn=1e5;
struct node{
	LL l,r,sum,lazy;
};
struct segmantree{
	node T[maxn<<2];
	void build(Int x,Int s,Int t,Int *val){
		T[x].l=s;T[x].r=t;T[x].lazy=0;
		if(s==t){
			T[x].sum=val[s];
			T[x].l=T[x].r=-1;
			return;
		}
		Int mid=(s+t)>>1;
		build(x<<1,s,mid,val);
		build((x<<1)+1,mid+1,t,val);
		T[x].sum=T[x<<1].sum+T[(x<<1)+1].sum;
	}
	void update(Int x,Int s,Int t,Int v){
		if(T[x].l>=s&&T[x].r<=t){
			T[x].lazy+=v;
			T[x].sum+=(v*(T[x].r-T[x].l+1));
			return;
		}
		if(T[x].lazy)pushdown(x);
		Int mid=(T[x].l+T[x].r)>>1;
		if(s<=mid)update(x<<1,s,t,v);
		if(t>mid)update((x<<1)+1,s,t,v);
		if(T[x].l!=-1)T[x].sum=T[x<<1].sum+T[(x<<1)+1].sum;
	}
	void pushdown(Int x){
		if(T[x].l==-1)return;
		update(x<<1,T[x].l,T[x].r,T[x].lazy);
		update((x<<1)+1,T[x].l,T[x].r,T[x].lazy);
		T[x].sum=T[x<<1].sum+T[(x<<1)+1].sum;
	}
	Int query(LL x,LL s,LL t){
		if(T[x].l>=s&&T[x].r<=t)return T[x].sum;
		Int mid=(T[x].l+T[x].r)>>1,ans=0;
		if(s<=mid)ans+=query(x<<1,s,t);
		if(t>mid)ans+=query((x<<1)+1,s,t);
		return ans;
	}
};