#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,ans=0;
int main(){
	cin>>n>>m;
	if(n>=3&&m>=3){
		cout<<(n-2)*(m-2)<<endl;
		return 0;
	}
	if(n==1){
		if(m==1)cout<<1<<endl;
		else cout<<m-2<<endl;
		return 0;
	}
	if(m==1){
		cout<<n-2<<endl;
		return 0;
	}
	if(n==2){
		cout<<0<<endl;
		return 0;
	}
	if(m==2){
		cout<<0<<endl;
		return 0;
	}
	return 0;
}