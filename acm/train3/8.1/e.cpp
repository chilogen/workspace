#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	LL t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n%2==1)cout<<"Balanced\n";
		else cout<<"Bad\n";
	}
	return 0;
}