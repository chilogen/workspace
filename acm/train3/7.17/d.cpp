#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL t,w,d;
LL solve(LL a,LL b){
	LL i,j,l;
	i=a/2;
	j=b+1;
	l=i*j;
	if(a%2==1)l+=(b+1)/2;
	return l;
}
int main(){
	cin>>t;
	while(t--){
		cin>>w>>d;
		cout<<min(solve(w,d),solve(d,w))<<endl;
	}
	return 0;
}