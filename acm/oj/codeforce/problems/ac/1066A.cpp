#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL solve(){
	LL L,v,l,r,tot,covered=0;
	LL a,b;
	cin>>L>>v>>l>>r;
	tot=L/v;
	a=l/v*v;
	b=r/v*v+v;
	covered=(b-a)/v+1;
	if(a<l)covered--;
	if(b>r)covered--;
	return tot-covered;
}
int main(){
	LL t;
	cin>>t;
	while(t--)cout<<solve()<<endl;
	return 0;
}