#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL one=1;
LL n,c,a[60],ans=0;
bool cmp(LL x,LL y){return x>y;}
int main(){
	LL i;
	cin>>n>>c;
	for(i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,cmp);
	for(i=0;i<n;i++){
		if(c>a[i]){
			ans+=(one<<(n-i-1));
			c-=a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}