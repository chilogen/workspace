#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10;

struct node{
	LL v,ind,sum,lef,rig;
}T[maxn<<2];

LL a[maxn],b[maxn],n,q;

void build(LL x,LL l,LL r){
	T[x].lef=l;T[x].rig=r;
	if(l==r){
		T[x].v=a[l];
		T[x].ind=b[l];
		T[x].sum=a[l]*b[l];
		return ;
	}
	LL mid=(l+r)>>1;
	build(x<<1,l,mid);
	build((x<<1)+1,mid+1,r);
	T[x].sum=T[x<<1].sum+T[(x<<1)+1].sum;
	T[x].v=T[x<<1].v+T[(x<<1)+1].v;
}

void update(LL x,LL p,LL v){
	if(T[x].lef==T[x].rig){
		T[x].v=v;
		T[x].sum=v*T[x].ind;
		return;
	}
	LL mid=(T[x<<1].lef+T[x].rig)>>1;
	if(p<=mid)update(x<<1,p,v);
	else update((x<<1)+1,p,v);
	T[x].sum=T[x<<1].sum+T[(x<<1)+1].sum;
	T[x].v=T[x<<1].v+T[(x<<1)+1].v;
}

pair<LL,LL> sum(LL x,LL l,LL r){
	if(T[x].lef>=l&&T[x].rig<=r)return make_pair(T[x].v,T[x].sum);
	LL mid=(T[x].lef+T[x].rig)>>1;
	pair<LL,LL> ans=make_pair(0,0),tmp;
	if(l<=mid){
		tmp=sum(x<<1,l,r);
		ans.first+=tmp.first;
		ans.second+=tmp.second;
	}
	if(r>mid){
		tmp=sum((x<<1)+1,l,r);
		ans.first+=tmp.first;
		ans.second+=tmp.second;
	}
	return ans;
}

LL ans(LL l,LL r){
	pair<LL,LL>tmp=sum(1,l,r);
	LL k=n-r;
	return tmp.second-tmp.first*k;
}

void solve(){
	cin>>n>>q;
	LL i,j,k,l,m;
	for(i=1,k=n;i<=n;i++,k--){
		cin>>a[i];
		b[i]=k;
	}
	build(1,1,n);
	for(i=0;i<q;i++){
		cin>>j>>k>>l;
		if(j==1){
			m=ans(k,l);
			cout<<m<<endl;
		}
		else{
			update(1,k,l);
		}
	}
}

int main(){
	solve();
	return 0;
}