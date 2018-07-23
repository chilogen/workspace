#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,x;
LL a,gg;
int main(){
	cin>>n>>x;
	cin>>a;n--;
	gg=a;
	while(n--){
		cin>>a;
		gg=__gcd(gg,a);
	}
	cout<<(x%gg==0?"YES\n":"NO\n");
	return 0;
}