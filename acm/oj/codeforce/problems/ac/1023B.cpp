#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k;
bool check(LL x){
	LL y=k-x;
	if(y>n)return false;
	return true;
}
int main(){
	cin>>n>>k;
	LL i,j,l,r,mid;
	l=1;r=n;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	j=k-l;
	if(j<=0||j>n){
		cout<<0<<endl;
		return 0;
	}
	i=j-l+1;
	cout<<i/2<<endl;
	return 0;
}