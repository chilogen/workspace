#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b,r,s,t;
string ans1="The first one is winner.\n";
string ans2="The second one is winner.\n";
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>a>>b>>r;
		r*=2;
		if(r<=a&&r<=b)cout<<ans1;
		else cout<<ans2;
	}
	return 0;
}