#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL prime[]={103127047,984466009,653452649,
378452077,475201777,915279049,379146109,
110954237,510750281,392857511,296005727,
378297167,811592627,222398747,100812793,
906533717,336385711,989985119,639420011,289273939,
};

string s;
LL len;
LL mpow(LL x,LL y,LL mod){
	LL k=x,a=1;

	//exception
	if(x==0)return 1;
	
	while(y){
		if(y&1){
			a*=k;
			a%=mod;
		}
		y>>=1;
		k*=k;
		k%=mod;
	}
	return a;
}
bool check(LL p){
	LL i,n=0;
	for(i=0;i<len;i++){
		n*=10;
		n+=(s[i]-'0');
		n%=p;
	}
	if(mpow(n,(p-1)/2,p)==1)return true;
	return false;
}
int main(){
	LL i;
	cin>>s;
	len=s.length();
	for(i=0;i<20;i++){
		if(!check(prime[i])){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	return 0;
}