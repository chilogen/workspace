#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,ans,i,j,l;
int main(){
	cin>>n>>k;
	for(i=k;i<n;i++)
		ans+=(n-i);
	for(i=k+1;i<n;i++){
		j=n/i;
		ans+=((i-k)*(j-1));
		l=n-j*i;
		ans+=max((LL)0,l-k+1);
	}
	if(k==0)cout<<n*n<<endl;
	else cout<<ans<<endl;
	return 0;
}