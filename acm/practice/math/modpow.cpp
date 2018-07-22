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
int main(){
	cout<<modpow(2,4)<<endl;
	return 0;
}