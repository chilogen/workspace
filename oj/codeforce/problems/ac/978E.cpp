#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,w,ma=0,mi=0;
int main(){
	LL i,j,k;
	cin>>n>>w;
	for(i=0,k=0;i<n;i++){
		cin>>j;
		k+=j;
		ma=max(ma,k);
		mi=min(mi,k);
	}
	j=0-mi;	ma+=j;
	cout<<max((LL)0,w-ma+1);
	return 0;
}