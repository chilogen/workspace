#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10;
LL a[maxn],b[maxn],c[maxn]={0},n,opt,l,r,d;
inline LL lowbit(LL x){return x&-x;}
inline void update(LL x){
	LL v=0;
	while(x<=n){
		v+=b[x];b[x]=0;
		c[x]+=v;
		x+=lowbit(x);
	}
}
inline LL query(LL x){
	LL ans=0;
	while(x>0){
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	LL i;
	cin>>n;
	for(i=1,a[0]=0;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=a[i]-a[i-1];
	}
	for(i=1;i<=n;i++){
		if(b[i]!=0)update(i);
	}
	for(i=0;i<n;i++){
		scanf("%lld%lld%lld%lld",&opt,&l,&r,&d);
		if(opt==0){
			b[l]=d;
			update(l);
			b[r+1]=-d;
			update(r+1);
		}
		if(opt==1)	printf("%lld\n",query(r));
	}
	return 0;
}