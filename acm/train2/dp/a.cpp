#include <bits/stdc++.h>
using namespace std;
int n,dp[200010],a[200010];
int main(){
	int i,j,k;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	j=1;
	dp[0]=a[0];
	for(i=1;i<n;i++){
		k=lower_bound(dp,dp+j,a[i])-dp;
		dp[k]=a[i];
		j=max(j,k+1);
	}
	cout<<j<<endl;
	return 0;
}