#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL mod;
LL mpow(LL x,LL y){
	LL j=1,k=x;
	while(y){
		if(y&1){
			j*=k;
			j%=mod;
		}
		y>>=1;
		k*=k;
		k%=mod;
	}
	return j;
}
int main(){
	LL n,a,b,cnt,x,y;
	cin>>n>>a;
	mod=1ll<<n;
	cnt=0;
	for(b=1;b<=mod;b++){
		x=mpow(a,b);y=mpow(b,a);
		if(mpow(a,b)==mpow(b,a)){
			cout<<b<<endl;
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}