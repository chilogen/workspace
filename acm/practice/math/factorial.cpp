#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
const Int mod=1e9+7;


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

inline Int inv(Int x){return modpow(x,mod-2);}

Int factorial(Int x){
	Int ans=1;
	while(x--){
		ans*=x;
		ans%=mod;
		if(x==0)return 0;
	}
	return ans;
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
	return (xf*inv(yf))%mod;
}

int main(){
	int i;
	for(i=1;i<=20;i++){
		cout<<factorial_div(i*2,i)<<" ";
	}
	return 0;
}