#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ans,a[100050],p1[100050],p2[100050],sum[100050],t,len;
char c[100050];
const LL mod=1e9+7;
inline void solve(){
	LL i,j,k,m,n;
	for(i=0;i<len;i++){
		m=p2[i];	j=max(len-2-i,(LL)0);	
		n=p1[j];	k=len-i-2;
		if(i!=len-1) ans=ans+((m*n)%mod)*sum[k]+((a[k+1]*p1[j+1])%mod)*m;
		else ans=ans+(a[0]*p2[len-1])%mod;
		ans%=mod;
	}
	cout<<ans<<endl;
}
void init(){
	LL i,two=2,ten=10;
	p1[0]=1;	p2[0]=1;
	for(i=1;i<100050;i++){
		p1[i]=p1[i-1]*two;
		p2[i]=p2[i-1]*ten;
		p1[i]%=mod;
		p2[i]%=mod;
	}
}
int main(){
	cin>>t;
	int i;
	init();
	while(t--){
		ans=0;
		scanf("%s",c);
		len=strlen(c);
		for(i=0;i<len;i++)a[i]=c[i]-'0';
		sum[0]=a[0];
		for(i=1;i<len;i++){
			sum[i]=a[i]+sum[i-1];
			sum[i]%=mod;
		}
		solve();
	}
	return 0;
}