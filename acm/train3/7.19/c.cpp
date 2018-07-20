#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
Int n,mod,t;
Int modpow(Int x,Int y){
	Int ans=1,tmp=x;
	while(y){
		if(y&1){
			ans*=tmp;
			ans%=mod;
		}
		y>>=1;
		tmp*=tmp;
		tmp%=mod;
	}
	return  ans;
}

Int factorial_div(Int x,Int y){
	Int cnt=0,xf=1,yf=1,i,v;
	for(i=2;i<=y;i++){
		v=i;
		while(v%mod==0){
			cnt++;
			v/=mod;
		}
		yf*=v;
		yf%=mod;
	}
	for(i=y+1;i<=x;i++){
		v=i;
		while(v%mod==0){
			cnt--;
			v/=mod;
		}
		xf*=v;
		xf%=mod;
	}
	if(cnt!=0)return 0;
	return (xf*modpow(yf,mod-2))%mod;
}
int main(){
	Int i,j,k,l;
	cin>>t;
	while(t--){
		cin>>n>>mod;
		j=k=1;
		for(i=0;i<n;i++){
			l=j+k;
			l%=mod;
			k=j;
			j=l;
		}
		k=0;
		if(n%2==0){
			k=factorial_div(n,n/2);
			k=(k-(n/2+1)%mod+mod)%mod;
		}
		cout<<(k+j)%mod<<endl;
	}
	return 0;
}