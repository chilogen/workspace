//TLE

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e5+10,inf=1e16;
LL a[maxn],s[maxn],n,t,ans=0;
struct node{
	LL l,r,mid,mi,ma;
	node(){}
	node(LL x,LL y){
		l=x;r=y;
		mid=(x+y)>>1;
	}
}T[maxn<<2];
void maintain(LL x){
	T[x].mi=min(T[x<<1].mi,T[(x<<1)+1].mi);
	T[x].ma=max(T[x<<1].ma,T[(x<<1)+1].ma);
}

void build(LL x,LL l,LL r){
	T[x]=node(l,r);
	if(l==r){
		T[x].mi=T[x].ma=s[l];
		return;
	}
	build(x<<1,l,T[x].mid);
	build((x<<1)+1,T[x].mid+1,r);
	maintain(x);
}

LL query(LL x,LL l,LL r,LL v){
	if(T[x].mi>=v)return 0;
	if(T[x].ma<v)return T[x].r-T[x].l+1;
	LL tans=0;
	if(l<=T[x].mid)tans+=query(x<<1,l,r,v);
	if(r>T[x].mid)tans+=query((x<<1)+1,l,r,v);
	return tans;
}

void solve(){
	LL i;
	cin>>n>>t;
	for(i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	build(1,1,n);
	for(i=1;i<=n;i++){
		ans+=query(1,i,n,t);
		t+=a[i];
	}
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	solve();
	return 0;
}