#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAXN 300010
LL a[MAXN],D[20*MAXN]={0};
LL l[MAXN<<4]={0},r[MAXN<<4]={0},sum[MAXN<<4]={0};
LL n,m;
void build(LL x,LL s,LL e){
	l[x]=s;r[x]=e;
	if(s==e){
		sum[x]=a[s];
		return;
	}
	LL mid=(s+e)>>1;
	build(x<<1,s,mid);
	build((x<<1)+1,mid+1,e);
	sum[x]=sum[x<<1]+sum[(x<<1)+1];
}
LL update(LL x,LL p,LL v){
	LL i,j,mid;
	if(l[x]==r[x]&&l[x]==p){
		i=v-sum[x];
		sum[x]=v;
		a[p]=v;
		return i;
	}
	mid=(l[x]+r[x])>>1;
	if(p<=mid)	i=update(x<<1,p,v);
	else i=update((x<<1)+1,p,v);
	sum[x]+=i;
	return i;
}
LL query(LL x,LL s,LL e){
	if(l[x]>=s&&r[x]<=e)	return sum[x];
	LL mid=(l[x]+r[x])>>1;
	LL i=0,j=0;
	if(s<=mid)	i=query(x<<1,s,e);
	if(e>mid)	j=query((x<<1)+1,s,e);
	return i+j;	
}
set<int>s;
int main(){
	LL i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>2)	s.insert(i);
	}
	for(i=1;i<=1000000;i++){
		for(j=1;i*j<=1000000;j++)
			D[i*j]++;
	}
	build(1,1,n);
	while(m--){
		scanf("%lld%lld%lld",&i,&j,&k);
		if(i==2){
			cout<<query(1,j,k)<<endl;
		}
		else{
			vector<int>v;
			while(1){
				auto x=s.lower_bound(j);
				if(x==s.end()||*x>k)	break;
				v.push_back(*x);
				s.erase(x);
			}
			auto x=v.begin();
			while(x!=v.end()){
				update(1,*x,D[a[*x]]);
				x++;
			}
		}
	}
	return 0;
}