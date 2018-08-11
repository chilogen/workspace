#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e18;
int main(){
	LL a,b,c,k;
	cin>>a>>b>>c>>k;
	if(k%2==0)cout<<a-b<<endl;
	else cout<<b-a<<endl;
	return 0;
}