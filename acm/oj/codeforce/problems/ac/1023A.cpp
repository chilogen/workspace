#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s,t;
LL n,m;
int main(){
	cin>>n>>m;
	cin>>s>>t;
	LL i,j,k=0;
	for(i=0;i<n;i++)if(s[i]=='*'){k=1;break;}
	if(k){
		k=i;
		if(m<n-1){
			cout<<"NO\n";
			return 0;
		}
		for(i=0;i<k;i++){
			if(s[i]==t[i])continue;
			cout<<"NO\n";
			return 0;
		}
		for(i=n-1,j=m-1;i>k;i--,j--){
			if(s[i]==t[j])continue;
			cout<<"NO\n";
			return 0;
		}
		cout<<"YES\n";
	}
	else{
		if(n!=m)cout<<"NO\n";
		else{
			for(i=0;i<n;i++)if(s[i]!=t[i]){
				cout<<"NO\n";
				return 0;
			}
			cout<<"YES\n";
		}
	}
	return 0;
}