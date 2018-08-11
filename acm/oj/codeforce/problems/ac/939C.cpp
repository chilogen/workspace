#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAXN 100010
struct node{
	LL l,r,v,lazy;
	node(){
		l=r=-1;
		v=lazy=0;
	}
}t[MAXN<<5];
LL n,a[MAXN],s,f;
void build(LL x,LL left,LL right){
	t[x].l=left;
	t[x].r=right;
	if(left==right)	return;
	LL mid=(left+right)>>1;
	build(x<<1,left,mid);
	build((x<<1)+1,mid+1,right);
}
void insert(LL x,LL left,LL right,LL val){
	if(t[x].l>=left&&t[x].r<=right){
		t[x].lazy+=val;
		return;
	}
	LL mid=(t[x].l+t[x].r)>>1;
	if(left<=mid)insert(x<<1,left,right,val);
	if(right>mid)insert((x<<1)+1,left,right,val);
}
void pushdown(LL x){
	if(t[x].lazy!=0){
		t[x].v+=t[x].lazy;
		if(t[x].l==t[x].r){
			a[t[x].l]=t[x].v;
			return;
		}
		t[x<<1].lazy+=t[x].lazy;
		t[(x<<1)+1].lazy+=t[x].lazy;
	}
	pushdown(x<<1);
	pushdown((x<<1)+1);
}
int main(){
	LL i,j,k,ts,tf;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	cin>>s>>f;
	f--;
	build(1,1,n);
	for(i=1;i<=n;i++){
		ts=s-(i-1);tf=f-(i-1);
		if(ts<1)ts+=n;
		if(tf<1)tf+=n;
		if(ts<=tf){
			insert(1,ts,tf,a[i]);
		}
		else{
			insert(1,ts,n,a[i]);
			insert(1,1,tf,a[i]);
		}
	}
	pushdown(1);
	for(i=1,k=1,j=a[k];i<=n;i++){
		if(a[i]>j){
			k=i;
			j=a[k];
		}
	}
	cout<<k<<endl;
	return 0;
}