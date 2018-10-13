#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=998244353;
LL s[200010]={0};
int main(){
	LL n,m,i,k,ans=0;
	string s1,s2;
	cin>>n>>m>>s1>>s2;
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	while(s1.length()<s2.length())s1+='0';
	while(s2.length()<s1.length())s2+='0';
	n=m=s1.length()-1;
	for(i=n;i>=0;i--)s[i]=s[i+1]+(s2[i]-'0');
	for(i=0,k=1;i<=n;i++){
		if(s1[i]=='0'){
			k=(k*2)%mod;
			continue;
		}
		ans+=(k*s[i]);
		ans%=mod;
		k=(k*2)%mod;
	}
	cout<<ans<<endl;
	return 0;
}