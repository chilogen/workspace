#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
string a;
LL k,ans=0;
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
};
int main(){
	cin>>a>>k;
	LL i,q,qn,qinv,l=a.length();
	for(i=0;i<l;i++){
		if(a[i]!='0'&&a[i]!='5')continue;
		ans+=ppow(2,i);
		ans%=mod;
	}
	q=ppow(2,l);
	qn=ppow(q,k);
	qinv=ppow(q-1,mod-2);
	ans=(ans*(qn-1)%mod*qinv)%mod;
	cout<<ans<<endl;
	return 0;
}