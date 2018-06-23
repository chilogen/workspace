#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL l,r,x,y;
int main(){
	LL k1,k2,j,k,a,b,ans=0;
	cin>>l>>r>>x>>y;
	if(y%x!=0){
		cout<<0<<endl;
		return 0;
	}
	if(x==y){
		if(x<=r&&x>=l)cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	k=y/x;
	j=sqrt(k)+1;
	for(k1=1;k1<=j;k1++){
		k2=k/k1;
		if(k1*k2!=k)continue;
		if(k1>=k2)continue;
		if(__gcd(k1,k2)!=1)continue;
		a=k1*x;
		b=k2*x;
		if(a*b!=x*y)continue;
		if(a<l||a>r||b<l||b>r)continue;
		ans+=2;
	}
	cout<<ans<<endl;
	return 0;
}