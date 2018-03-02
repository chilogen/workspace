#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL n,k,a,b,ans,i,j;
	cin>>n>>k>>a>>b;
	if(k==1){
		cout<<a*(n-1)<<endl;
		return 0;
	}
	ans=0;
	while(n>1){
		if(n%k==0){
			i=n/k;
			j=a*(n-i);
			if(j<b)ans+=j;
			else ans+=b;
			n=i;
		}
		else{
			i=n/k;
			if(i==0){
				ans+=(a*(n-1));
				break;
			}
			j=k*i;
			ans+=(a*(n-j));
			n=j;
		}
	}
	cout<<ans<<endl;
	return 0;
}