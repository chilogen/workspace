#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,a[100010],t[100010],sum[100010]={0},ans=0,tans=0;
int main(){
	LL i,l;
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		cin>>t[i];
		if(t[i]==1)ans+=a[i];
	}
	for(i=1;i<=n;i++){
		if(t[i]==0)sum[i]=sum[i-1]+a[i];
		else sum[i]=sum[i-1];
	}
	for(i=1;i<=n;i++){
		l=min(i+k-1,n);
		tans=max(tans,sum[l]-sum[i-1]);
	}
	cout<<ans+tans<<endl;
	return 0;
}