#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=5e4+10;
struct node{
	LL sum,left,right,sumof0;
}T[maxn<<2];
LL a[maxn],n;
void build(LL x,LL l,LL r){
	T[x].left=l;T[x].right=r;
	if(l==r){
		T[x].sum=a[l];
		T[x].sumof0=a[l]==0?1:0;
		return ;
	}
	LL mid=(l+r)>>1;
	build(x<<1,l,mid);
	build((x<<1)+1,mid+1,r);
	T[x].sum=T[x<<1].sum+T[(x<<1)+1].sum;
	T[x].sumof0=T[x<<1].sumof0+T[(x<<1)+1].sumof0;
}
void update(LL x,LL l,LL r){
	if(T[x].left==T[x].right){
		T[x].sum=sqrt(T[x].sum);
		return ;
	}
	LL mid=(T[x].left+T[x].right)>>1;
	if(l<=mid&&T[x<<1].sum>(T[x<<1].right-T[x<<1].left+1-T[x<<1].sumof0))
		update(x<<1,l,r);
	if(r>mid&&T[(x<<1)+1].sum>(T[(x<<1)+1].right-T[(x<<1)+1].left+1-T[x].sumof0))
		update((x<<1)+1,l,r);
	T[x].sum=T[x<<1].sum+T[(x<<1)+1].sum;
}
LL query(LL x,LL l,LL r){
	if(T[x].left>=l&&T[x].right<=r)return T[x].sum;
	LL mid=(T[x].left+T[x].right)>>1;
	LL j=0;
	if(l<=mid)	j+=query(x<<1,l,r);
	if(r>mid)j+=query((x<<1)+1,l,r);
	return j;
}
int main(){
	LL opt,l,r,c;
	LL i;
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	build(1,1,n);
	while(n--){
		scanf("%lld%lld%lld%lld",&opt,&l,&r,&c);
		switch(opt){
			case 0:{
				update(1,l,r);
				break;
			}
			case 1:{
				cout<<query(1,l,r)<<endl;
				break;
			}
		}
	}
	return 0;
}