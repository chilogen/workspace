#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b;
void solve(){
	LL x=a,y=b,z=b-1,sum,ans;
	x+=z;y-=z;
	z=x-1;
	sum=(1+z)*z/2;
	z=b-1;
	if(x%2==0)ans=sum-z+x;
	else ans=sum+z+1;
	cout<<ans<<endl;
}
int main(){
	cin>>a>>b;
	solve();
	return 0;
}