#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[100010];
int main(){
	LL i,j,k,l,ans;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1)l=i;
	}
	k=n-l;
	j=k/(m-1);
	ans=j;
	for(i=n-ans*(m-1)-1;i>0;i-=(m-1))
		ans++;
	cout<<ans<<endl;
	return 0;
}