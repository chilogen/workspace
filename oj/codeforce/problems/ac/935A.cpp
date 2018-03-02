#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,i,rem,ans=0;
	cin>>n;
	for(i=1;i<=n;i++){
		rem=n-i;
		if(rem==0)continue;
		if(rem%i==0)ans++;
	}
	cout<<ans<<endl;
	return 0;
}