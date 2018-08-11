#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL const mod=1e9+9;
LL ppow(LL x,LL y){
	LL ans=1,mul=x;
	while(y){
		if(y&1){
			ans=(ans*mul)%mod;
		}
		y=y>>1;
		mul=(mul*mul)%mod;;
	}
	return ans;
}
LL getinv(LL x){
	return ppow(x,mod-2);
}
LL n,a,b,x=0,k;
int main(){
	string s;
	cin>>n>>a>>b>>k;
	cin>>s;
	LL i,A=ppow(a,n),B=1,inva=getinv(a);
	LL ak=ppow(a,k),bk=ppow(b,k),invak=getinv(ak);
	for(i=0;i<k;i++){
		if(s[i]=='+'){
			x=(x+A*B)%mod;
		}
		else{
			x=(x+mod-A*B)%mod;
		}
		A=(A*inva)%mod;
		B=(B*b)%mod;
	}
	while(x<0)x+=mod;
	LL q=(invak*bk)%mod,invq=getinv(mod+1-q),qn=ppow(q,(n+1)/k);
	if(q==1){
		cout<<(x*((n+1)/k))%mod<<endl;
		return 0;
	}
	LL k=(1-qn);
	while(k<0)k+=mod;
	k=(k*invq)%mod;
	cout<<(x*k)%mod<<endl;
	return 0;
}