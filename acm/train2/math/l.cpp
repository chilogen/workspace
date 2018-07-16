#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7,maxn=100010;
LL ppow(LL x,LL y){
	LL ans=1,tans=x;
	while(y){
		if(y&1){
			ans*=tans;
			ans%=mod;
		}
		y>>=1;
		tans*=tans;
		tans%=mod;
	}
	return ans;
}
int main(){
	LL n,c1,c2,a,b,i,j;
	cin>>n;
	c1=c2=i=1;
	while(n--){
		a=4*i-2;
		b=i+1;
		j=__gcd(a,b);
		a/=j;
		b/=j;
		c1=c2;
		j=__gcd(b,c1);
		b/=j;
		c1/=j;
		j=ppow(b,mod-2);
		c2=((c1*a)%mod)*j;
		c2%=mod;
		i++;
	}
	cout<<c2<<endl;
	return 0;
}