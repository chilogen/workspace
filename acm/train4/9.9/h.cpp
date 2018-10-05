#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10;
LL a[maxn],b[maxn],c[maxn],n,q;
LL t[maxn];
inline LL lowbit(LL x){return x&(-x);}

void insert(LL x){
	LL v=0;
	for(LL i=x;i<maxn;i+=lowbit(i)){
		v+=a[i];
		a[i]=0;
		t[i]+=v;
	}
}
LL que1(LL x){
	LL ans=0;
	for(LL i=x;i>0;i-=lowbit(i))
		ans+=t[i];
	return ans;
}
LL query(LL l,LL r){
	LL ans,a,b,c,d;
	a=que1(r);b=que1(l-1);c=que1(l-2);d=b-c;
	ans=a-b-d*(r-l+1);
	return ans;
}

void update(LL x,LL v){
	for(LL i=x;i<maxn;i+=lowbit(i))t[i]+=v;
}

void solve(){
	LL i,k;
	LL type,l,r;
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	for(i=1,a[0]=0;i<=n;i++){
		a[i]+=a[i-1];
	}
	for(i=1;i<=n;i++){
		if(a[i]==0)continue;
		insert(i);
	}
	for(i=0;i<q;i++){
		cin>>type>>l>>r;
		if(type==1){
			k=query(l,r);
			cout<<k<<endl;
		}
		else{
			k=r-c[l];
			c[l]=r;
			update(l,k);
		}
	}
}

int main(){
	solve();
	return 0;
}