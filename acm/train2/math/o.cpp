#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL d,k,a,b,t;
int main(){
	cin>>d>>k>>a>>b>>t;
	if(d<=k){
		cout<<d*a<<endl;
		return 0;
	}
	if(a*k+t>b*k){
		cout<<a*k+b*(d-k)<<endl;
		return 0;
	}
	LL ans=1e18,repairs,x,t1,tans;
	repairs=d/k;
	ans=a*d+repairs*t;
	while(repairs){
		x=repairs*k;
		tans=repairs*k*a+(repairs-1)*t;
		t1=(d-x)*b;
		tans+=t1;
		if(tans>ans)break;
		ans=tans;
		repairs--;
	}
	cout<<ans<<endl;
	return 0;
}