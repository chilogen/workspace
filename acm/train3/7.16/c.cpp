#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,b,a,x,ans;
int main(){
	while(1){
		cin>>b;
		if(b==0)break;
		b*=2;
		for(n=1;n<100000;n++){
			x=b+n-n*n;
			if(x<=0)continue;
			if(x%(2*n)!=0)continue;
			ans=n;
		}
		cout<<(b+ans-ans*ans)/(2*ans)<<" "<<ans<<endl;
	}
}