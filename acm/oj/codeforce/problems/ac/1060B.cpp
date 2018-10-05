#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL f(LL x){
	LL ans=0;
	while(x){
		ans+=x%10;
		x/=10;
	}
	return ans;
}
int main(){
	LL n,a=0,i=1,j;
	cin>>n;
	while(1){
		a+=(i*9);
		if(a<n){
			i*=10;
			continue;
		}
		a-=(i*9);
		j=n/i-1;
		a+=(i*j);
		break;
	}
	cout<<f(a)+f(n-a)<<endl;
	return 0;
}