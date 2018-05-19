#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Maxn=1e6,inf=1e10;
struct node{
	LL left,right,Max,Min,sum;
}T[Maxn<<2];
LL n,m,o,x,y;
LL a[Maxn];
LL ma,mi,su;
void build(LL k,LL l,LL r){
	LL mid=(l+r)>>1;
	T[k].left=l;	T[k].right=r;
	T[k].Max=T[k].Min=T[k].sum=0;
	if(l==r)return;
	build(k<<1,l,mid);
	build((k<<1)+1,mid+1,r);
}
void update(LL k,LL ind,LL v){
	if(T[k].left==T[k].right){
		T[k].Min=T[k].Max=T[k].sum=v;
		return;
	}
	LL mid=(T[k].left+T[k].right)>>1;
	if(ind<=mid)update(k<<1,ind,v);
	else update((k<<1)+1,ind,v);
	T[k].Max=max(T[k<<1].Max,T[(k<<1)+1].Max);
	T[k].Min=min(T[k<<1].Min,T[(k<<1)+1].Min);
	T[k].sum=T[k<<1].sum+T[(k<<1)+1].sum;
}
void query(LL k,LL l,LL r){
	if(T[k].left>=l&&T[k].right<=r){
		su+=T[k].sum;
		ma=max(ma,T[k].Max);
		mi=min(mi,T[k].Min);
		return;
	}
	LL mid=(T[k].left+T[k].right)>>1;
	if(l<=mid)query(k<<1,l,r);
	if(r>mid)query((k<<1)+1,l,r);
}
int main(){
	cin>>n>>m;
	memset(a,0,sizeof(a));
	build(1,1,n);
	while(m--){
		scanf("%lld%lld%lld",&o,&x,&y);
		switch(o){
			case 0:{
				update(1,x,y);
				break;
			}
			case 1:{
				ma=-inf;mi=inf;
				su=0;
				query(1,x,y);
				printf("%lld\n",su-ma-mi);
				break;
			}
		}
	}
	return 0;
}

