#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e6+10;
struct node{
	LL ind,Min,mid;
}T[maxn<<2];
LL n,c,l;
void build(LL x,LL l,LL r){
	if(l==r){
		T[x].Min=-1;
		T[x].ind=l;
		return ;
	}
	LL mid=(l+r)>>1;
	T[x].mid=mid;
	build(x<<1,l,mid);
	build((x<<1)+1,mid+1,r);
	T[x].Min=-1;
	T[x].ind=-1;
}
LL query(LL x,LL v){
	if(T[x].ind!=-1){return T[x].ind;}
	if(T[x<<1].Min<v)return query(x<<1,v);
	else return query((x<<1)+1,v);
}
void update(LL x,LL k,LL v){
	if(T[x].ind!=-1){
		T[x].Min=v;
		return ;
	}
	if(k<=T[x].mid)update(x<<1,k,v);
	else update((x<<1)+1,k,v);
	T[x].Min=min(T[x<<1].Min,T[(x<<1)+1].Min);
}
int main(){
	LL i,j;
	cin>>n;
	build(1,1,n+10);
	update(1,1,0);
	for(i=1;i<=n;i++){
		scanf("%lld",&c);
		l=max((LL)0,i-c);
		j=query(1,l);
		printf("%lld ",j);
		update(1,j,i);
	}
	return 0;
}