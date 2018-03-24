#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL k[700]={0},n;
const LL mod=1e9+7;
int main(){
	LL i,j,l;
	cin>>n;
	for(i=1;i<=n-1;i++){
		l=0;
		for(j=i;j>=1;j--){
			l+=i*j;
			l%=mod;
		}
		k[i]=(k[i-1]+l)%mod;
	}
	l=0;
	for(i=n-1;i>=1;i--){
		for(j=i;j>=1;j--){
			l+=(i*j*k[j]);
			l%=mod;
		}
	}
	cout<<l<<endl;
	return 0;
}