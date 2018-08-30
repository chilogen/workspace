#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10;

struct aaaaaaaaaaaaaaaa{
	LL l,r,v;
}T[maxn<<2];

LL a[maxn];

void build(LL x,LL l,LL r){
	T[x].l=l;T[x].r=r;
	if(l==r){
		T[x].v=a[l];
		return;
	}
	LL mid=(l+r)>>1;
	build(x<<1,l,mid);
	build((x<<1)+1,mid+1,r);
	T[x].v=__gcd(T[x<<1].v,T[(x<<1)+1].v);
}

LL query(LL x,LL v){
	LL ans=0;
	if(T[x].v==v)ans++;
	if(T[x].v<v)return ans;
	if(T[x].l==T[x].r)return ans;
	ans+=query(x<<1,v);
	ans+=query((x<<1)+1,v);
	return ans;
}

void solve(){
	LL n,m,i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>a[i];
	build(1,1,n);
	for(i=0;i<m;i++){
		cin>>j;
		cout<<query(1,j)<<" ";
	}
}

int main(){
	LL t;
	cin>>t;
	while(t--)solve();
	return 0;
}