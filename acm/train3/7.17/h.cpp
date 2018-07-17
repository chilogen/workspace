#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,n,a[2010],ans;
int main(){
	int i,j;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(i=1;i<=2*n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++){
			j=2*n-i+1;
			ans=max(ans,a[i]+a[j]);
		}
		cout<<ans<<endl;
	}
	return 0;
}