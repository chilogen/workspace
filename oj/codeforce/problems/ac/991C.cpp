#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
bool check(LL k){
	LL ans=0,t=n;
	while(t>0){
		t-=k;
		if(t>0)t-=(t/10);
		ans+=k;
	}
	ans+=t;
	if(ans>=n/2+n%2)return 1;
	else return 0;
}
int main(){
	LL l,r,mid;
	cin>>n;
	l=1;r=n;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}